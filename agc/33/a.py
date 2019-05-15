import numpy as np

H, W = list(map(int, input().split()))

A = np.zeros((H, W))

for i in range(H):
    ipt = input()
    for j in range(W):
        if ipt[j] == '#':
            A[i, j] = 1


def calc(B, i, j):
    if i == 0:
        B[1, j] += 1
    elif i == H - 1:
        B[H - 2, j] += 1
    else:
        B[i-1, j] += 1
        B[i+1, j] += 1

    if j == 0:
        B[i, 1] += 1
    elif j == W - 1:
        B[i, W-2] += 1
    else:
        B[i, j-1] += 1
        B[i, j+1] += 1

    return B


def search(C):
    if len(np.nonzero(C)[0]) == H * W:
        return 0

    u = np.where((C < 4) & (C > 0))
    for r, c in zip(u[0], u[1]):
        calc(C, r, c)

    return search(C) + 1


print(search(A))
