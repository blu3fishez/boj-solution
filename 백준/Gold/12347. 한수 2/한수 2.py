n = int(input())

ans = 0

# 공차의 시작점은 계산할 때 중복되므로 예외처리 하자

def solve(val, d):
    global ans

    while True:
        cur_digit = (val % 10) + d
        
        if cur_digit < 0 or cur_digit > 9:
            break

        val = val*10 + cur_digit

        if val <= n:
            ans += 1
        else:
            break
        


for i in range(1, 10):
    if i <= n:
        ans += 1
    for d in range(-9, 10):
        solve(i, d)

print(ans)