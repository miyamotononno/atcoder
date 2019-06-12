H, W = list(map(int, input().split()))
grids = [[1]*W for i in range(H)]

cnt = [[] for i in range(H)]
for i in range(H):
    S = input()
    for j in range(W):
        if S[j] == '#':
            grids[i][j] = 0

