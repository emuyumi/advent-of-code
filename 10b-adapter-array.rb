file = File.new("test.txt", "r")
arr = [0]
while (line = file.gets)
  arr.push(line.to_i)
end
arr = arr.sort
arr.push(arr[-1]+3)
cnt = []
for i in 0..arr[-1]+1 do cnt[i]=0 end
cnt[0] = 1
for i in 1..arr.count-1 do
    cnt[arr[i]] = cnt[arr[i] - 1] + cnt[arr[i] - 2] + cnt[arr[i] - 3]
end
puts cnt[arr[-1]]
file.close