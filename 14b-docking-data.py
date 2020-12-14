def go(s, val):
    global mem
    cnt = s.count("X")
    for mask in range(0,1 << cnt):
        curr = 0
        p = 0
        for i in range(0, 36):
            curr *= 2
            if (s[i] == 'X'):
                curr += 1 & (mask >> p)
                p += 1
            else:
                curr += int(s[i])
        mem[curr] = val

f = open("test.txt", "r")
mem = dict()
mask =""
for s in f:
    x = s.split()
    if (x[0] == "mask"):
        x[-1] = "\"" + x[-1][::-1] + "\""
        exec("".join(x))
    else:
        add = int(x[0][4:-1])
        ans = ""
        for i in range(35, -1, -1):
	        if (mask[i] == '0'):
		        ans += str(1 & (int(add) >> i))
	        else:
		        ans += mask[i]
        go(ans, int(x[-1]))
print(sum(mem.values()))
