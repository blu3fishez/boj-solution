# 너넨 맞왜틀하지마라...

from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")
# uncomment if u use recursion
setrecursionlimit(10 ** 6)

preset = ((0, 1), (1, 0), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1))

def get_number(cord, board):
    cnt = 0
    for x in preset:
        next = tuple(map(sum, zip(cord, x)))

        if not (0 <= next[0] < len(board) and 0 <= next[1] < len(board)):
            continue

        if board[next[0]][next[1]] == '*': cnt += 1
    return cnt

def click(cord, board, is_first_click):
    for x in preset:
        next = tuple(map(sum, zip(cord, x)))
        
        if not (0 <= next[0] < len(board) and 0 <= next[1] < len(board)):
            continue
        
        if board[next[0]][next[1]] == '.':
            if board[cord[0]][cord[1]] == '0':
                board[next[0]][next[1]] = f'{get_number(next, board)}'
                if board[next[0]][next[1]] == '0':
                    click(next, board, False)

            elif get_number(next, board) == 0 and is_first_click:
                board[next[0]][next[1]] = '0'
                click(next, board, False)
            
for tc in range(int(rr())):
    ans = 0
    n = int(rr())
    board = []
    for _ in range(n):
        board.append(list(rr()))
    for i in range(n):
        for j in range(n):
            
            if board[i][j] == '.':
                # print((i,j))
                
                board[i][j] = f'{get_number((i, j), board)}'
                click((i, j), board, True)
                # for l in board:
                #     print(" ".join(l))
                ans += 1

    print(f'Case #{tc+1}: {ans}')