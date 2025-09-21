from sys import stdin, setrecursionlimit
rr = lambda: stdin.readline().rstrip("\r\n")

for _ in range(int(rr())):
    a, op, b, eq, c = rr().split()

    a, b, c = int(a), int(b), int(c)

    if op == '+':
        res = (a + b) == c
    elif op == '-':
        res = (a - b) == c
    elif op == '*':
        res = (a * b) == c
    elif op == '/':
        res = (a // b) == c
    
    if res:
        print('correct')
    else:
        print('wrong answer')