N = int(input())
for i in range(N):
    A, B = [int(t) for t in input().split()]
    if A == B:
        print(-1)
    else:
        gap = max(A, B) - min(A, B)
        print(gap)
