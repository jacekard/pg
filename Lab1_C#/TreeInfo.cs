using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lab1 {
    class TreeInfo {
        public static void PrintDirectoryFiles(DirectoryInfo root, bool recursive, int depth) {
            FileInfo[] files = null;
            DirectoryInfo[] dirs = null;

            files = root.GetFiles();
            dirs = root.GetDirectories();

            for (int i = 0; i < depth; i++) {
                Console.Write("  ");
            }
            if (files != null) {
                Console.Write(root.Name + " (" + (files.Length + dirs.Length) + ") " + root.getRahs() + '\n');
                if (recursive) {
                    foreach (var dir in dirs) {
                        PrintDirectoryFiles(dir, true, depth + 1);
                    }
                }
                foreach (var f in files) {
                    for (int i = 0; i < depth + 1; i++) {
                        Console.Write("  ");
                    }
                    Console.Write(f.Name + " " + f.Length + " bajtow  " + f.getRahs() + '\n');
                }
            }
        }
    }

    static class FileSystemInfoExtension {
        public static string getRahs(this FileSystemInfo info) {
            char[] rahs = "----".ToCharArray();
            var attr = info.Attributes;
            
            rahs[0] = (attr & FileAttributes.ReadOnly) == FileAttributes.ReadOnly ? 'r' : '-';
            rahs[1] = (attr & FileAttributes.Archive) == FileAttributes.Archive ? 'a' : '-';
            rahs[2] = (attr & FileAttributes.Hidden) == FileAttributes.Hidden ? 'h' : '-';
            rahs[3] = (attr & FileAttributes.System) == FileAttributes.System ? 's' : '-';

            return new string(rahs);
        }

        public static DateTime getOldestElementDate(this DirectoryInfo di) {
            FileInfo[] files = di.GetFiles();
            DirectoryInfo[] dirs = di.GetDirectories();
            DateTime date = DateTime.Today.AddDays(1);
            foreach (FileInfo f in files) {
                if (f.LastWriteTime < date) {
                    date = f.LastWriteTime;
                }
            }
            foreach (DirectoryInfo d in dirs) {
                DateTime ret = getOldestElementDate(d);
                if (ret < date) {
                    date = ret;
                }
            }

            return date;
        }

    }
}

