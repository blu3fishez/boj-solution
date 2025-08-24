from sys import stdin, setrecursionlimit
input = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
# sys.setrecursionlimit(10 ** 6)

n, l, w, h = map(int, input().split())

sz = min(l, w, h)

cnt_l = l//sz
cnt_w = w//sz
cnt_h = h//sz

cnt = cnt_l * cnt_w * cnt_h

while cnt < n:
    next_val = max(l/(cnt_l + 1), w/(cnt_w + 1), h/(cnt_h + 1))

    if abs(next_val - l/(cnt_l + 1)) <= 10e-18:
        cnt_l += 1
    elif abs(next_val - w/(cnt_w + 1)) <= 10e-18:
        cnt_w += 1
    else:
        cnt_h += 1

    sz = next_val

    cnt = cnt_l * cnt_w * cnt_h

print("{:.10f}".format(sz))