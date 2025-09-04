from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

words = {}

def f(q):
    qd = {}
    for t in q:
        qd[t] = qd.get(t, 0) + 1

    results = []
    for key, value in words.items():
        if all(value.get(qk, 0) == cnt and len(value) == len(qd) for qk, cnt in qd.items()):
            results.append(key)

    return sorted(results)

while True:
    l = rr()
    if l == "XXXXXX":
        break
    val = dict()
    for t in l:
        val[t] = val.get(t, 0) + 1
    words[l] = val

while True:
    q = rr()
    if q == "XXXXXX":
        break
    
    results = f(q)

    if len(results) == 0:
        print("NOT A VALID WORD\n******")
    else:
        print('\n'.join(results)); print("******")
    
