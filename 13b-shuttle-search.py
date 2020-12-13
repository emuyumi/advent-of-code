l = open("test.txt", "r").readlines()
cnt = 0
mod = 1
val = 0
for x in l[1].split(","):
    if (x != 'x'):
        x = int(x)
        while (val % x != (x - cnt) % x):
            val += mod
        mod *= x
    cnt += 1
print(val)