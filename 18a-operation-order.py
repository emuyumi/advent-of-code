idx = 0

def solve():
    global idx
    op = ""
    ret = 0
    val = 0
    while idx < len(s):
        if (s[idx] == '+'): op = '+'
        elif (s[idx] == '*'): op = '*'
        elif (s[idx] == ')'): return ret
        else:
            if (s[idx] == '('):
                idx += 1
                val = solve()
            else:
                val = int(s[idx])
            if op == "": ret = val
            elif op == "+": ret += val
            else: ret *= val
        idx += 1
    return ret

f = open("test.txt", "r")
ans = 0
for s in f:
    idx = 0
    s = s.replace(" ","").strip()
    ans += solve()
print(ans)
