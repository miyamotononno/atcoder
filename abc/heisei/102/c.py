import bisect as bi

N = int(input())
A = [int(t) for t in input().split()]

A = sorted([A[i]-i-1 for i in range(N)])

nega_cnt = bi.bisect_left(A, 0)
posi_cnt = N - bi.bisect_right(A, 0)
zero_cnt = N - nega_cnt - posi_cnt


def calc():
    if nega_cnt + zero_cnt >= posi_cnt and posi_cnt + zero_cnt >= nega_cnt:
        return sum([abs(t) for t in A])

    if posi_cnt > nega_cnt + zero_cnt:
        idx = (posi_cnt-(nega_cnt + zero_cnt)) // 2 + 1
        a = A[-posi_cnt:][idx-1]
        return sum([abs(t-a) for t in A])

    if posi_cnt + zero_cnt < nega_cnt:
        idx = (nega_cnt-(posi_cnt + zero_cnt))//2 + 1
        a = A[:nega_cnt][-idx]
        return sum([abs(t-a) for t in A])


print(calc())
