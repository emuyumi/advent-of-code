l = open("test.txt", "r").readlines()
t = int(l[0])
ans = t - 1
f = lambda x : int(t / x) * x + x - t
for x in l[1].split(","):
    if (x=='x'): continue
    x = int(x)
    if (f(x) < f(ans)):
        ans = x
print(ans * f(ans))