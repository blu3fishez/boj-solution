from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# setrecursionlimit(10 ** 6)

n,u,l,d = map(int, rr().split())

is_alert = False
cnt = 0
ans = 0

for i in map(int, rr().split()):
    if is_alert:
        if i <= l:
            cnt += 1
        else:
            cnt = 0
        
        if cnt == d:
            is_alert = False
            cnt = 0
    else:
        if i >= u:
            cnt += 1
        else:
            cnt = 0
        
        if cnt == d:
            is_alert = True
            ans += 1
            cnt = 0

print(ans)