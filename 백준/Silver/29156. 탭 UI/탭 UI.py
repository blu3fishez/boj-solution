from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
from math import floor

n = int(rr())

arr = [0]
presum = [0]

for _ in range(n):
    arr.append(int(rr()))
    presum.append(presum[-1] + arr[-1])
tab_size = int(rr())
output = []

mx_tab = max(presum[n] - tab_size, 0)

for _ in range(int(rr())):
    q = int(rr())
    value = presum[q-1] - tab_size/2 + arr[q]/2
    value = max(0, value)
    value = min(value, mx_tab)
    output.append(f"{value:.2f}")

print("\n".join(output))