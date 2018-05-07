using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Lab1 {
    class Program {
        static void Main(string[] args) {
            if (args[0] == null) {
                Console.WriteLine("No path as argument line specified");
                return;
            }

            bool opt = true;
            DirectoryInfo dir = new DirectoryInfo(Path(args));

            TreeInfo.PrintDirectoryFiles(dir, opt, 0);

            Console.WriteLine();
            Console.WriteLine(dir.getOldestElementDate());
            Console.WriteLine();

            //zadanie 5
            List<FileInfo> files = new List<FileInfo>(dir.GetFiles());
            List<DirectoryInfo> dirs = new List<DirectoryInfo>(dir.GetDirectories());
            FileSystemInfoComparer comparer = new FileSystemInfoComparer();
            SortedDictionary<string, long> sortedDictionary = new SortedDictionary<string, long>(comparer);

            foreach (var f in files) {
                sortedDictionary.Add(f.Name, f.Length);
            }
            foreach (var d in dirs) {
                long dirLength = 0;
                try {
                    dirLength += d.GetFiles().Length;
                    dirLength += d.GetDirectories().Length;
                }
                catch (Exception e) {

                };
                sortedDictionary.Add(d.Name, dirLength);
            }

            // zad 6
            // serialization
            BinaryFormatter binaryFormatter = new BinaryFormatter();
            FileStream writeFile = new FileStream("dict.txt", FileMode.Create);
            binaryFormatter.Serialize(writeFile, sortedDictionary);
            writeFile.Close();
            // deserialize
            FileStream readFile = new FileStream("dict.txt", FileMode.Open);
            SortedDictionary<string, long> deserialized = (SortedDictionary<string, long>)binaryFormatter.Deserialize(readFile);
            readFile.Close();

            foreach (var e in deserialized) {
                Console.WriteLine(e.Key, e.Value);
            }
        }

        public static string Path(string[] args) {
            string path = null;
            foreach(var a in args) {
                path += a + ' ';
            }
            return (path.Substring(0, path.Length-1));
        }
    }

}
