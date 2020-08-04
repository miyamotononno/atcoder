N, M = list(map(int, input().split()))

U = [[0]*M for i in range(N)]

for i in range(N):
    A = list(map(int, input().split()))
    K = A[0]
    A = A[1:]
    for j in range(K):
        t = A[j] - 1
        U[i][t] = 1

cnt = 0
for i in range(M):
    cnt2 = 0
    for j in range(N):
       cnt2 += U[j][i]
       if cnt2 == N:
           cnt +=1

print(cnt)