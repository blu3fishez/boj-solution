from sys import stdin
rr = lambda: stdin.readline().rstrip("\r\n")

n, k = map(int, rr().split())
a = sorted(list(map(int, rr().split())))

'''
점진적으로 마시기 -> 의미 없음
'''

lo, hi = 0, len(a) - 1
has_lowered = True
current_taste = 0
ans = 0

for _ in range(k):
    if has_lowered:
        ans += a[hi] - current_taste
        has_lowered = False
        hi -= 1
    else:
        current_taste = a[lo]
        has_lowered = True
        lo += 1

print(ans)