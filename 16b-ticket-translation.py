f = open("test.txt", "r")
valid = [0 for i in range(0, 1000)]
fields = []
pos = []
my = []
for x in f:
    if (x == "\n"):
        continue
    if (x[0].isdigit()):
        x = x.strip().split(",")
        if (my == []):
            my = x
        bad = 0
        for val in x:
            if (not valid[int(val)]):
                bad = 1
        if (bad):
            continue
        for i in range(0, 20):
            val = int(x[i])
            for j in range(0, 20):
                if (not int(fields[j][0]) <= val <= int(fields[j][1]) and not int(fields[j][2]) <= val <= int(fields[j][3])):
                    if (i in pos[j]):
                        pos[j].remove(i)
    else:
        x = x.strip().split()
        if (len(x) == 2):
            continue
        pos.append([i for i in range(0, 20)])
        fields.append(x[-3].split("-") + x[-1].split("-"))
        temp = x[-3].split("-")
        for i in range(int(temp[0]), int(temp[1]) + 1):
            valid[i] = 1
        temp = x[-1].split("-")
        for i in range(int(temp[0]), int(temp[1]) + 1):
            valid[i] = 1
ans = 1
for i in range(0, 20):
    rem = 0
    for j in range(0, 20):
        if (len(pos[j]) == 1):
            rem = j
    if (0 <= rem <= 5):
        ans *= int(my[pos[rem][0]])
    rem = pos[rem][0]
    for j in range(0, 20):
        if (rem in pos[j]):
            pos[j].remove(rem)
print(ans)
    
    