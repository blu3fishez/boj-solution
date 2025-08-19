'''
처음에 바로 생각난건 누적합. 그야 생긴게 그래서 (부배열에서 흠칫.)

하지만 누적합만으론 안됨을 깨달았음. 애초에 문제에서 요구하는건 합이 T인걸 만족하는 경우의 수. 따라서 부배열 값들을 배열로 그냥 변환해서 경우의 수를 찾아내서 그냥 직접 더하면 된다.
근데 이때 편하게 계산하려면 누적합이 필요하다.
이때 정렬을 해도 문제가 없으므로 정렬하게 되면 슬라이딩 윈도우를 사용할 수 있게 된다.

부배열의 합의 경우의 수를 정렬 해보자.
부배열의 합을 모두 구한다 -> 1000*1000 / 1000*1000 -> 2_000_000

정렬해서 슬라이딩 윈도우로 증가/감소하는 구간을 찾아내면 된다.

1_000_000*log(1_000_000) = 6_000_000 * 2 -> 12_000_000

이후에 슬라이딩 윈도우를 쓸려고 했는데, 틀렸음. 생각해보면 그럴만도함.

a_l = 4 4 4 4 4
b_l = 4 4 4 4 4 라고 하면, 절대로 다 못찾는다. 이걸 슬라이딩 윈도우한다고 하면 이상하다.

그래서 그냥 특정 수를 찾는거면 되니까, T - a_l[i] 를 만족하는 수가 있는지만 보면 된다.

python에서는 multi_set은 없어서 그냥 dict로 풀었다.
'''

T = int(input())
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

ans = 0

a_p, b_p = [[0 for _ in range(0, n)] for _ in range(0, n)], [[0 for _ in range(0, m)] for _ in range(0, m)]

a_l = []
b_s = dict()

for i in range(0, n):
    for j in range(0, i + 1):
        a_p[j][i] = a_p[j][i-1] + a[i]
        a_l.append(a_p[j][i])

for i in range(0, m):
    for j in range(0, i + 1):
        b_p[j][i] = b_p[j][i-1] + b[i]
        b_s[b_p[j][i]] = b_s.get(b_p[j][i], 0) + 1

a_l.sort()

ea = len(a_l) - 1
sb = 0

for i in range(0, len(a_l)):
    ans += b_s.get(T - a_l[i], 0)
    
print(ans)
