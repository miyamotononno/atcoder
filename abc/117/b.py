N = int(input())
L = list(map(int, input().split()))

if 2*max(L) - sum(L) >= 0:
    print('No')
else:
    print('Yes')