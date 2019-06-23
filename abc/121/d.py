A, B = list(map(int, input().split()))


if (B - A +1) %2 == 1: 
    l = (B-A+1) // 2
    if l % 2 == 0:
        print(B)
    else:
        if B % 2 ==0:
            print(B+1)
        else:
            print(B-1)
else:
    l = (B-A+1) / 2
    if l % 2 == 0:
        print(0)
    else:
        print(1)
     
