from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# setrecursionlimit(10 ** 6)

m,n=map(int, rr().split())
satis = False
for _ in range(m):
    if any(map(lambda x: int(x) > 0, rr().split())):
        satis = True

if m<8 or not satis:
    print("unsatisfactory")
else:
    print("satisfactory")