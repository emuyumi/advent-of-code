using System;
using System.Collections.Generic;

class MainClass {
    public static void Main (string[] args) {
        System.IO.StreamReader file = new System.IO.StreamReader("test.txt"); 
        string line;
        List<int> vec = new List<int>();
        while((line = file.ReadLine()) != null) { 
            int curr = 0;
            foreach (char x in line){
                curr *= 2;
                if (x == 'B' || x == 'R') curr++;
            }
            vec.Add(curr);
        }
        vec.Sort();
        for (int i = 1; i < vec.Count; ++i){
            if (vec[i] - vec[i-1] != 1) Console.WriteLine(vec[i] - 1);
        }
    }
}