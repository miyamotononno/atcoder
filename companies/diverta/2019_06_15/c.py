N = int(input())

A = list(map(int, input().split()))
A.sort()
pA = []
nA = []
for a in A:
    if a < 0:
        nA.append(a)
    else:
        pA.append(a)

ans=[]
def calc():
    # pAもnAも長さが2以上ある場合
    if len(pA) > 0 and len(nA) > 0: 
        for i in range(len(pA) -1):
            ans.append([nA[0], pA[i]])
            nA[0] -=  pA[i]

        for i in range(len(nA) -1):
            ans.append([pA[-1], nA[-i-1]])
            pA[-1] -= nA[-i-1]

        ans.append([pA[-1], nA[0]])
        return pA[-1] - nA[0]
    elif not nA:
        for i in range(1,len(pA) -1):
            ans.append([pA[0], pA[i]])
            pA[0] -=  pA[i]

        ans.append([pA[-1], pA[0]])
        return pA[-1] - pA[0]
    elif not pA:
        for i in range(1,len(nA) -1):
            ans.append([nA[-1], nA[-i-1]])
            nA[-1] -=  nA[-i-1]

        ans.append([nA[-1], nA[0]])
        return nA[-1] - nA[0]


x = calc()

print(x)
for a in  ans:
    print(*a)