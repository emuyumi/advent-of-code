local arr = {}
local vis = {}
local file = io.open("test.txt", "r")
local p = 0
for str in file:lines() do
    p = p + 1
    arr[p] = str
    vis[p] = false
end
p = 1
local ans = 0
while not vis[p] do
    vis[p] = true
    local cmd = string.sub(arr[p], 1, 3)
    local num = tonumber(string.sub(arr[p], 5))
    if cmd == "acc" then
        ans = ans + num
    elseif cmd == "jmp" then
        p = p + num - 1 
    end
    p = p + 1
end
print(ans)

