from sys import stdin
rr = lambda: stdin.readline().rstrip("\r\n")

primes = [True for _ in range(100001)]
primes[1] = False
p = []

for i in range(2, 100001):
    if primes[i] == False: continue
    p.append(i)
    for j in range(2*i, 100001, i):
        primes[j] = False
ans = []
for _ in range(int(rr())):
    n = int(rr())
    a = sorted(list(map(int, rr().split())))
    b = score = float('inf')
    
    for i in range(len(p) - n):
        s = 0
        for j in range(i, i + n):
            s += abs(p[j] - a[j - i])
        if s < score:
            score = s
        
    ans.append(str(score))

print('\n'.join(ans))