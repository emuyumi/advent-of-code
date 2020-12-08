function solve(bad)
    local p = 1
    local ans = 0
    for i = 1, #arr do
        vis[i] = false
    end
    while p <= #arr do
        if vis[p] then
            return -1
        end
        vis[p] = true
        local cmd = string.sub(arr[p], 1, 3)
        local num = tonumber(string.sub(arr[p], 5))
        if cmd == "acc" then
            ans = ans + num
        elseif p == bad and cmd == "nop" then
            p = p + num - 1
        elseif cmd == "jmp" and p ~= bad then
            p = p + num - 1 
        end
        p = p + 1
    end
    return ans
end

arr = {}
vis = {}
local file = io.open("test.txt", "r")
local p = 0
for str in file:lines() do
    p = p + 1
    arr[p] = str
    vis[p] = false
end

for i = 1, #arr do
    if string.sub(arr[i], 1, 3) ~= "acc" then
        local temp = solve(i)
        if temp ~= -1 then
            print(temp)
            break
        else
        end
    end
end

