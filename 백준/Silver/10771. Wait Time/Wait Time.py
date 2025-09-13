from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# setrecursionlimit(10 ** 6)

q = {}
times = {}
current_time = 0

for _ in range(int(rr())):
    cmd, t = rr().split()
    t = int(t)
    
    
    if cmd == 'R':
        q[t] = current_time
        current_time += 1
    if cmd == 'S':
        times[t] = times.get(t, 0) + current_time - q[t]
        q[t] = -1
        current_time += 1
    elif cmd == 'W':
        current_time += int(t) - 1

for i in sorted(q.keys()):
    if q[i] != -1:
        print(f"{i} -1")
    else:
        print(f"{i} {times[i]}")