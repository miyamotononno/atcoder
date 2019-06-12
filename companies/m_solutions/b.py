S = input()


w = 0
l = 0
for s in S:
    if s == 'o':
        w+=1
    else:
        l+=1

if (15 - len(S) + w >=8):
    print('YES')
else:
    print('NO')
