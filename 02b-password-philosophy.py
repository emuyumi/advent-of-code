f = open("test.txt", "r")
ans = 0
for s in f:
    x = s.split()
    l, r = map(int, x[0].split("-"))
    ans += (x[2][l - 1] == x[1][0]) + (x[2][r - 1] == x[1][0]) == 1
print(ans)