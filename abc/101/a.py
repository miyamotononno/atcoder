S = input()

cnt = 0
for s in S:
    if s == '+':
        cnt += 1
    else:
        cnt -= 1

print(cnt)
