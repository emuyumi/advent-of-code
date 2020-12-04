open System.IO
open System.Text.RegularExpressions

let input = File.ReadAllText("test.txt", System.Text.Encoding.UTF8)
let a = input.Split("\n\n")
let arr = [|"byr:";"iyr:";"eyr:";"hgt:";"hcl:";"ecl:";"pid:"|]
let good (s : string) : bool =
    let mutable ans = 0
    ans <- ans + if (Regex.IsMatch(s, "byr:(19[2-9][0-9]|200[0-2])( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "iyr:(201[0-9]|2020)( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "eyr:(202[0-9]|2030)( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "hgt:(((1[5-8][0-9]|19[0-3])cm)|((59|6[0-9]|7[0-6])in))( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "hcl:#([a-f]|[0-9]){6}( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "ecl:(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)( |$|\n)")) then 1 else 0
    ans <- ans + if (Regex.IsMatch(s, "pid:\d{9}( |$|\n)")) then 1 else 0
    // printfn "%d" ans
    ans = 7
let go (x : seq<string>) : int =
    let mutable ans = 0
    for item in x do
        ans <- ans + if (good(item)) then 1 else 0
    ans
printfn "%d\n" (go a)