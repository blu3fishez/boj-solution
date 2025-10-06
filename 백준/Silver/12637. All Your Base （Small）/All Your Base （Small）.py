from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

s = []
for tc in range(int(rr())):
    inp = rr()
    zero_key, one_key = None, None
    sz = 0
    m = {}
    for t in inp:
        if not t in m:
            if sz == 0:
                zero_key = t
            if sz == 1:
                one_key = t
            m[t] = sz; sz += 1
    
    m[zero_key] = 1
    m[one_key] = 0
    
    ans = 0
    sz = max(2, sz)
    for i, t in enumerate(reversed(inp)):
        ans += (sz ** i) * m[t]
    s.append(str(f"Case #{tc+1}: {ans}"))
    

print('\n'.join(s))