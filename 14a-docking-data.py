f = open("test.txt", "r")
mem = ["0b0" for i in range(100000)]
mask =""
for s in f:
    x = s.split()
    if (x[0] == "mask"):
        x[-1] = "\"" + x[-1][::-1] + "\""
        exec("".join(x))
    else:
        ans = ""
        for i in range(35, -1, -1):
	        if (mask[i] == 'X'):
		        ans += str(1 & (int(x[-1]) >> i))
	        else:
		        ans += mask[i]
        x[-1] = "\"0b" + ans + "\""
        exec("".join(x))
print(sum(map(lambda a : int(a, 2), mem)))
