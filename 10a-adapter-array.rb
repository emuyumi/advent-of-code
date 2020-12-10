file = File.new("test.txt", "r")
arr = [0]
while (line = file.gets)
  arr.push(line.to_i)
end
arr = arr.sort
arr.push(arr[-1]+3)
cnt1 = 0
cnt3 = 0
for i in 1..arr.count-1 do
    puts arr[i]
    if arr[i]-arr[i-1] == 1 then cnt1+=1 end
    if arr[i]-arr[i-1] == 3 then cnt3+=1 end
end
puts cnt1*cnt3
file.close