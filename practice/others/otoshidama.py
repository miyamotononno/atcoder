# -*- coding: utf-8 -*-

N, Y = map(int, input().split())
ans = (-1, -1, -1)
for x in range(N+1):
    for y in range(N + 1 - x):
        z = N - x - y
        if 10000*x + 5000*y + 1000*z == Y:
            ans = (x, y, z)
            break

print(ans[0], ans[1], ans[2])


"""回答"""
# N, Y = map(int, input().split())
# res = (-1, -1, -1)
# for x in range(N + 1):
#     for y in range(N + 1 - x):
#         if N - x - y >= 0 and 10000*x + 5000*y + 1000*(N - x - y) == Y:
#             res = (x, y, N - x - y)
# print(res[0], res[1], res[2])
