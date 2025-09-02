from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

n = int(rr())

for i in range(n):
    x, y = map(int, rr().split())
    if i == 0:
        mx = (x, y)
        mn = (x, y)
    else:
        mx = (max(mx[0], x), max(mx[1], y))
        mn = (min(mn[0], x), min(mn[1], y))

print(abs(mx[0]-mn[0])*abs(mx[1]-mn[1]))