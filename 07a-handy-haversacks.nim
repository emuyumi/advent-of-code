import strutils
import tables
import lists
import os

var map = initTable[string, int]()
var str = ""
var bag:int = 0
var adj : array[701, SinglyLinkedList[int]]
var vis : array[701, bool]
for i in 0..700:
    adj[i] = initSinglyLinkedList[int]()
    vis[i] = false
var i = 0
for line in lines "test.txt":
    var arr = line.split(" ")
    if (arr[^3] == "no"):
        continue
    if (not map.hasKey(arr[0] & arr[1])):
        bag += 1
        map[arr[0] & arr[1]] = bag
        #echo arr[0] & arr[1], bag
    var curr = map[arr[0] & arr[1]]
    var idx = 5
    while idx < arr.len:
        if (not map.hasKey(arr[idx] & arr[idx + 1])):
            bag += 1
            map[arr[idx] & arr[idx + 1]] = bag
            #echo arr[idx] & arr[idx + 1], bag
        var curr1 = map[arr[idx] & arr[idx + 1]]
        idx = idx + 4
        adj[curr1].append(curr)

var stk: seq[int] = @[map["shinygold"]]
vis[map["shinygold"]] = true
var ans = 0
while stk.len > 0:
    var v = stk.pop()
    for to in adj[v]:
        if (not vis[to]):
            vis[to] = true
            ans = ans + 1
            stk.add(to)
echo ans