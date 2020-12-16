f = open("test.txt", "r")
valid = [0 for i in range(0, 1000)]
ans = 0
for x in f:
    if (x == "\n"):
        continue
    if (x[0].isdigit()):
        x = x.strip().split(",")
        for val in x:
            if (not valid[int(val)]):
                ans += int(val)
    else:
        x = x.strip().split()
        if (len(x) == 2):
            continue
        temp = x[-3].split("-")
        for i in range(int(temp[0]), int(temp[1]) + 1):
            valid[i] = 1
        temp = x[-1].split("-")
        for i in range(int(temp[0]), int(temp[1]) + 1):
            valid[i] = 1
print(ans)