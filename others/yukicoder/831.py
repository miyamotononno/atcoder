N = int(input())

left = N//2
right = N - left

A = [i+1 for i in range(N)]
left = A[:N//2]
right = sorted(A[- N//2:], reverse=True)

ans = 0
len_left = len(left)
if len_left == len(right):
    for i in range(len_left):
        if i == 0:
            ans += left[i]*right[i]

        if i == len_left - 1:
            ans += left[i]*right[i]
            break

        if i != len_left - 1:
            ans += left[i]*right[i+1]
            ans += left[i+1]*right[i]

    print(ans)
else:
    for i in range(len_left):
        if i == 0:
            ans += left[0]*right[0]

        if i == len_left - 1:
            ans += left[i]*right[i+1]
            ans += right[i]*right[i+1]
            break

        ans += left[i]*right[i+1]
        ans += left[i+1]*right[i]

    print(ans)
