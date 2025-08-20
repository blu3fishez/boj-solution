from sys import stdin, setrecursionlimit
input = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

c, n = map(int, input().split())

dp = [-1 for _ in range(0, c + 1)]
arr = []

for i in range(0, n):
    # arr[i][0] - 비용
    # arr[i][1] - 유치 고객
    arr.append(tuple(map(int, input().split())))
    

dp[0] = 0

for i in range(0, n):
    for j in range(0, c + 1):
        if dp[j] == -1:
            continue
        persons = j + arr[i][1]
        cost = dp[j] + arr[i][0]

        if persons > c:
            persons = c

        if dp[persons] == -1 or cost <= dp[persons]:
            dp[persons] = cost

print(dp[c])