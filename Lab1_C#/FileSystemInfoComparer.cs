﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1 {
    [Serializable]
    class FileSystemInfoComparer : IComparer<string> {
        public int Compare(string x, string y) {
            if(x.Length == y.Length) {
                return x.CompareTo(y);
            } else {
                return x.Length - y.Length;
            }
        }
    }
}
