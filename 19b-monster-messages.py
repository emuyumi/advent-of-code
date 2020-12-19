rules = [[] for i in range(150)]
valid = [set() for i in range(150)]

def go(x):
    if len(valid[x]) != 0:
        return
    curr = set()
    for s in rules[x]:
        if s.isnumeric():
            s = int(s)
            go(s)
            if (len(curr) == 0):
                curr = valid[s]
                continue
            temp = set()
            for i in curr:
                for j in valid[s]:
                    temp.add(i+j)
            curr = temp
        elif s == '|':
            valid[x] = valid[x].union(curr)
            curr = set()
        else:
            curr.add(s[1])
    valid[x] = valid[x].union(curr)

f = open("test.txt","r").readlines()
f = list(map(lambda x : x.strip().split(), f))

while f[0] != []:
    rules[int(f[0][0][:-1])] = f[0][1:]
    f.pop(0)
f.pop(0)

go(31)
go(42)
dist = len(next(iter(valid[31])))
ans = 0
print(valid[42], valid[31])
for message in f:
    message = message[0]
    n = len(message)
    if (n % dist != 0):
        continue
    parts = [message[i:i+dist] for i in range(0, n, dist)]
    n = len(parts)
    idx = 0
    while (idx < n - 1):
        if (not parts[idx] in valid[42]):
            break
        idx += 1
    if (idx < (n+1)/2):
        continue
    while (idx < n):
        if (not parts[idx] in valid[31]):
            break
        idx += 1
    if (idx == n):
        ans += 1
print(ans)
