from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
from queue import PriorityQueue

n, m = map(int, rr().split())
tpq = PriorityQueue()
spq = PriorityQueue()

for t in map(int, rr().split()):
    tpq.put(t)
for s in map(int, rr().split()):
    spq.put(s)
ans = 0
while not spq.empty() and not tpq.empty():
    space = spq.get()
    task = tpq.queue[0]
    if space >= task:
        ans += 1
        tpq.get()
print(ans)