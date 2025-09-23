from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

def is_symmetric(st):
    s = 0
    e = len(st) - 1
    while s <= e:
        if st[s] != st[e]:
            return False
        s += 1
        e -= 1    
    return True

ans = []
for _ in range(int(rr())):
    s = rr()
    org_s = s
    idx = 0
    if is_symmetric(s):
        ans.append(s)
        continue

    while idx < len(org_s):
        s = org_s + s[idx::-1]
        if is_symmetric(s):
            ans.append(s)
            break
        else:
            idx += 1
    
print("\n".join(ans))