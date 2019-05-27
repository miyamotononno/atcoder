N = int(input())

L = [[0]*2 for i in range(N)]

start_index = [0]*N
for i in range(N):
    A, B = [int(t) for t in input().split()]
    L[i] = [min(A, B), max(A, B)]

L2 = sorted(L, key=lambda x: x[0])
trgt = 1
ans_L = []
trgt_idx = -1
for i in range(N):
    if L2[i][0] != trgt:
        trgt = L2[i][0]
        ans_L.append(L2[i])
        trgt_idx = -1
    else:
        if not L2[i] in ans_L[trgt_idx:]:
            ans_L.append(L2[i])
            trgt_idx -= 1

print(len(ans_L))
