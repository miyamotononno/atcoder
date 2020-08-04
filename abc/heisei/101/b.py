N = input()

s = sum([int(t) for t in N])

ans = 'Yes' if int(N) % s == 0 else 'No'

print(ans)
