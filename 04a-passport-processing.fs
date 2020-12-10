open System.IO

let input = File.ReadAllText("test.txt", System.Text.Encoding.UTF8)
let a = input.Split("\n\n")
let arr = [|"byr:";"iyr:";"eyr:";"hgt:";"hcl:";"ecl:";"pid:"|]
let good (s : string) : bool =
    let mutable ans = 0
    for item in arr do
        ans <- if (s.Contains(item)) then ans+1 else ans
    not (ans <> 7)
let go (x : seq<string>) : int =
    let mutable ans = 0
    for item in x do
        ans <- ans + if (good(item)) then 1 else 0
    ans
printfn "%d\n" (go a)