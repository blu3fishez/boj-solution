from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# setrecursionlimit(10 ** 6)
arr=[]
for _ in range(int(rr())):
    arr.append(int(rr()))
for i in sorted(arr):
    print(i)
