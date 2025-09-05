from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

n, m = map(int, rr().split())

w = []

for _ in range(n):
    l = rr().split()
    if l[0] == "order":
        tb, t = map(int, l[1:])
        w.append((t, tb))
    elif l[0] == "sort":
        w = sorted(w)
    elif l[0] == "complete":
        tb = int(l[1])
        for i in w:
            if i[1] == tb:
                w.remove(i)
                break

    if len(w) == 0:
        print("sleep")
    else:
        print(" ".join([str(i[1]) for i in w]))

