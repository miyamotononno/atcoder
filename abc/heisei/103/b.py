import copy

S = input()
T = input()

ans = 'No'
for i in range(len(S)):
    u = copy.copy(S)
    S = u[-1]+u[:-1]
    if S == T:
        ans = 'Yes'
        break

print(ans)
