from sys import stdin, setrecursionlimit
input = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

n,k = map(int, input().split())
arr = [0 for _ in range(n+1)]
for _ in range(k):
    arr[int(input())] = 1

watchers = set()
last_watcher = 0
ans = 0
for i in range(1, n+1):
    if arr[i] == 1:
        for j in range(last_watcher+1, i+1):
            watchers.add(j)
        last_watcher = i
    ans += len(watchers)
print(ans)