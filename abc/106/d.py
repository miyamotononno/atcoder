N, M, Q = list(map(int, input().split()))

trains = [[0]*N for j in range(N)]

for i in range(M):
    l, r = list(map(int, input().split()))
    trains[r-1][l-1] += 1

ans = [[0]*N for j in range(N)]
ans[0][0] = trains[0][0]

for e in range(1, N):  # endのe
    for s in reversed(range(N)):  # startのs
        if s == e:
            ans[e][s] = trains[e][s]
        else:
            ans[e][s] = sum(trains[e][s:]) + ans[e-1][s]


for i in range(Q):
    p, q = list(map(int, input().split()))
    print(ans[q-1][p-1])
