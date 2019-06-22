N = int(input())
S = input()

al = [chr(i) for i in range(97, 97+26)]
ans = 0
for i in range(N):
    a = S[i:]
    b = S[:i]
    cnt = 0
    for j in al:
        if j in a and j in b:
            cnt+=1

    ans = max(ans, cnt)

print(ans)