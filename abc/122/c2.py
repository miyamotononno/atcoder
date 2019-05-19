N, Q = list(map(int, input().split()))
S = input()

counts = [0]*N

count = 0
for i, (a, b) in enumerate(zip(S, S[1:])):
    if a == 'A' and b == 'C':
        count += 1
        counts[i+1] = count
    else:
        counts[i+1] = count

for i in range(Q):
    l, r = list(map(int, input().split()))
    print(counts[r-1] - counts[l-1])
