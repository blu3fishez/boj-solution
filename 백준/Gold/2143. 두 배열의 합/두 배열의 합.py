T = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

ans = 0

a_p, b_p = [[0 for _ in range(0, n)] for _ in range(0, n)], [[0 for _ in range(0, m)] for _ in range(0, m)]

a_l = []
b_s = dict()

for i in range(0, n):
    for j in range(0, i + 1):
        a_p[j][i] = a_p[j][i-1] + a[i]
        a_l.append(a_p[j][i])

for i in range(0, m):
    for j in range(0, i + 1):
        b_p[j][i] = b_p[j][i-1] + b[i]
        b_s[b_p[j][i]] = b_s.get(b_p[j][i], 0) + 1

a_l.sort()

ea = len(a_l) - 1
sb = 0

for i in range(0, len(a_l)):
    ans += b_s.get(T - a_l[i], 0)
    
print(ans)