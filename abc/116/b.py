s = int(input())

a = [s]
for i in range(1, 10000000):
    if a[i-1]%2 == 0:
        t = a[i-1]/2
    else:
        t = a[i-1]*3+1

    if t in a:
        print(i)
        break
    else:
        a.append(i)