'''
바로 냅색 문제를 생각했지만 까먹었다..!

인사이트만 머릿속에 남았었고, 직접 구현했어야했는데.. 문제는 n * c 만큼 돌리는 근거를 찾지 못했음

일단 c를 최대한 올려도 1까지만큼밖에 못올리는 경우밖에 없기 때문에 c번 반복했다. 약간 크루스칼에서 n-1 번 반복해야 MST가 완성되는 개념을 생각해냈다.
'''

from sys import stdin, setrecursionlimit
input = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

c, n = map(int, input().split())

dp = [-1 for _ in range(0, c + 1)] # C명 유치할 때 최소 비용
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
