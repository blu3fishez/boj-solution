from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

for _ in range(int(rr())):
    lastid = dict()
    rr(); l = list(rr())
    for (i, c) in enumerate(l):
        data = lastid.get(c, (0, 0))
        lastid[c] = (i, data[1] + 1)  # lastid, cnt
    
    
    l.sort(key=lambda x: lastid[x[0]])
    
    lastid_sort = dict()

    for (i, c) in enumerate(l):
        lastid_sort[c] = i

    ans = 0
    for key, data in lastid.items():
        ans += 5 * data[1] * (data[0] - lastid_sort[key])

    print(ans)