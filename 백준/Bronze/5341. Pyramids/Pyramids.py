from sys import stdin
rr = lambda: stdin.readline().rstrip("\r\n")

while True:
    inp = int(rr())
    if inp == 0:
        break
    print(inp*(inp+1)//2)