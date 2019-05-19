N = int(input())

ans = 'No'
for i in range(N//7 + 1):
    if (N - 7 * i) % 4 == 0:
        ans = 'Yes'
        break

print(ans)
