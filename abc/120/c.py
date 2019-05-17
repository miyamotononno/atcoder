# -*- coding: utf-8 -*-

S = input()
N = len(S)

cnt_0 = 0
cnt_1 = 0
for i in range(N):
    if S[i] == '0':
        cnt_0 += 1
    else:
        cnt_1 += 1

ans = N - abs(cnt_0 - cnt_1)
print(ans)
