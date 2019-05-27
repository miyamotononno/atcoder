import copy

N, M = map(int, input().split())
L = []

for i in range(M):
    k = list(map(int, input().split()))
    l = [i-1 for i in k[1:]]  # indexを渡していることに注意
    L.append(l)

p = list(map(int, input().split()))


def calc(idx, lampe):
    if idx == N:
        ans = 0
        for l in range(M):
            if sum([lampe[v] for v in L[l]]) % 2 != p[l]:
                return 0

        return 1

    ans = 0
    ans += calc(idx+1, lampe)
    lampe2 = copy.copy(lampe)
    lampe2[idx] = 1
    ans += calc(idx+1, lampe2)
    return ans


ans = calc(0, [0]*N)
print(ans)
