using System;

class MainClass {
    public static void Main (string[] args) {
        System.IO.StreamReader file = new System.IO.StreamReader("test.txt"); 
        int ans = 0, curr;
        string line;
        while((line = file.ReadLine()) != null) { 
            curr = 0;
            foreach (char x in line){
                curr *= 2;
                if (x == 'B' || x == 'R') curr++;
            }
            ans = Math.Max(curr, ans);
        }
        Console.WriteLine(ans);
    }
}