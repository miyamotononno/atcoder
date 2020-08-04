# -*- coding: utf-8 -*-

N = int(input())
h = list(map(int, input().split()))


def calc(list_h):
    if not list_h:
        return 0

    min_height = min(list_h)
    list_h = [list_h[i] - min_height for i in range(len(list_h))]
    zero_indexes = [i for i, x in enumerate(list_h) if x == 0]

    if not any(list_h):
        return min_height

    left_list = list_h[:zero_indexes[0]]
    right_list = list_h[zero_indexes[0]+1:]
    return calc(left_list) + calc(right_list) + min_height


print(calc(h))
