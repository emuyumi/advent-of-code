f = open("test.txt", "r")
ans = 0
for s in f:
    x = s.split()
    l, r = map(int, x[0].split("-"))
    ans += l <= x[2].count(x[1][0]) <= r
print(ans)