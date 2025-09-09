from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# setrecursionlimit(10 ** 6)

x1, y1, x2, y2, x3, y3 = map(int, rr().split() + rr().split() + rr().split())


outer_product = (x2-x1)*(y3-y2) - (y2-y1)*(x3-x2)

if outer_product > 0:
    print(1)
elif outer_product < 0:
    print(-1)
else:
    print(0)
