from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

n = int(rr())

cnt = 0
has_points = False

while n > 1:
    if n%2:
        has_points = True
    n //= 2
    cnt += 1

if n == 1 and has_points:
    cnt += 1

print(cnt + 1)