from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

mx = -1
ans = []
for _ in range(int(rr())):
    ans.append(int(rr()))

mx = max(ans)

n = int(mx)
mod = 1_000_000_007

dp = [0 for _ in range(2*n + 1)]

## 0~2n 번째 인덱스는 0번방만 사용
## 1,3,5... 2n-1번째 인덱스는 0, 1 번방 사용

dp[0] = 1
dp[1] = 3
dp[2] = 7

for i in range(3, 2*n + 1, 2):
    dp[i] = (dp[i-1] + dp[i-2]*2) % mod
    dp[i+1] = (dp[i-1]*2 + dp[i] + dp[i-2]*2) % mod
        

print('\n'.join(map(lambda x: str(dp[2*x]), ans)))