import collections
n, m = map(int, input().split())
A = [int(i) for i in input().split()]

R = [0]
a = 0
for i in range(n):
    a += A[i]
    a %= m
    R.append(a)


def nc2(n):
    return n*(n-1)//2


c = collections.Counter(R)
ans = 0
for r in set(R):
    ans += nc2(c[r])
print(ans)
