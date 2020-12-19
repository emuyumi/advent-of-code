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

go(0)
ans = 0
print(valid[0])
for message in f:
    if (message[0] in valid[0]):
        ans += 1
print(ans)
