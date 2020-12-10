import strutils
import tables
import lists
import deques
import os

type 
    pair = tuple[a:int, b:int]

var map = initTable[string, int]()
var str = ""
var bag:int = 0
var adj : array[701, SinglyLinkedList[pair]]
var deg : array[701, int]
var val : array[701, int]
for i in 0..700:
    adj[i] = initSinglyLinkedList[pair]()
    deg[i] = 0
    val[i] = 0
for line in lines "test.txt":
    var arr = line.split(" ")
    if (arr[^3] == "no"):
        continue
    if (not map.hasKey(arr[0] & arr[1])):
        bag += 1
        map[arr[0] & arr[1]] = bag
    var curr = map[arr[0] & arr[1]]
    var idx = 5
    while idx < arr.len:
        if (not map.hasKey(arr[idx] & arr[idx + 1])):
            bag += 1
            map[arr[idx] & arr[idx + 1]] = bag
        var curr1 = map[arr[idx] & arr[idx + 1]]
        adj[curr].append((curr1,parseInt(arr[idx - 1])))
        deg[curr1] = deg[curr1] + 1
        idx = idx + 4

var dq = initDeque[int]()
for i in 1..bag:
    if (deg[i] == 0):
        dq.addLast(i)
val[map["shinygold"]] = 1
var ans = -1
while dq.len > 0:
    var v = dq.popFirst()
    ans += val[v]
    for to in adj[v]:
        val[to.a] = val[to.a] + val[v] * to.b
        deg[to.a] = deg[to.a] - 1
        if (deg[to.a] == 0):
            dq.addLast(to.a)
echo ans