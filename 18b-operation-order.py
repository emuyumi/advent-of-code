idx = 0

def solve(exp):
    exp = list(map(eval,exp.split("*")))
    ret = 1
    for x in exp: ret *= x
    return ret
    
def proc():
    global idx
    ret = ""
    while idx < len(s):
        if (s[idx] == ')'): return solve(ret)
        elif (s[idx] == '('):
            idx += 1
            ret += str(proc())
        else:
            ret += s[idx]
        idx += 1
    return solve(ret)

f = open("test.txt", "r")
ans = 0
for s in f:
    idx = 0
    s = s.replace(" ","").strip()
    ans += proc()
print(ans)
