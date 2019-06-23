S = input()

ans = 'Good'
for i, j in zip(S,S[1:]):
    if i == j:
        ans = 'Bad'

print(ans)