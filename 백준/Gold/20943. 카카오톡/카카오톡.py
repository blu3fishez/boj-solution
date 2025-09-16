from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

def euclid(a, b):
    if a > b:
        a, b = b, a

    if a == 0:
        return b

    return euclid(b%a, a)

n = int(rr())
diffs = {} # lines[a][b] = count
horizontal = 0

for i in range(n):
    a, b, c = map(int, rr().split())
    
    # a, b 를 서로소로 만들기
    mod = euclid(abs(a), abs(b))

    ua = abs(a)//mod
    ub = abs(b)//mod
    
    if (a < 0 and b > 0) or (a > 0 and b < 0):
        a = ua
        b = -ub
    else:
        a = ua
        b = ub
    
    if a == 0:
        diffs[float('inf')] = diffs.get(float('inf'), 0) + 1
    else:
        diffs[b/a] = diffs.get(b/a, 0) + 1

for i in diffs.values():
    if i > 1:
        horizontal += i*(i-1)//2

print(n*(n-1)//2 - horizontal)