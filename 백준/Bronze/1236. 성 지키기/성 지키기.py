from sys import stdin
rr = lambda: stdin.readline().rstrip("\r\n")

h, w = map(int, rr().split())
board = []

for _ in range(h):
    board.append(list(rr()))

x, y = 0, 0
for i in range(h):
    empty = True
    for j in range(w):
        if board[i][j] == 'X':
            empty = False
            break
    if empty:
        x += 1

for j in range(w):
    empty = True
    for i in range(h):
        if board[i][j] == 'X':
            empty = False
            break
    if empty:
        y += 1

print(max(x, y))