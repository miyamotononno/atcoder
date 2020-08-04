# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))

cnt = 0
abs_A = []
for i in range(N):
    if A[i] < 0:
        cnt += 1
        abs_A.append(-A[i])
    else:
        abs_A.append(A[i])
ans = sum(abs_A)
if cnt % 2 != 0:
    ans -= 2*min(abs_A)

print(ans)
