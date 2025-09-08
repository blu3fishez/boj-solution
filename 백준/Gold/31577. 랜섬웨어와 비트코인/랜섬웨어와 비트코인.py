from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

num = 0

holders = [set() for _ in range(15)]

for i in range(120):
    for cur_hold in range(15):
        if num in holders[cur_hold] or len(holders[cur_hold]) == 8:
            continue
        holders[cur_hold].add(num)
        num = (num+1)%20

for i in range(15):
    for j in holders[i]:
        print(j+1, end=' ')
    print()

