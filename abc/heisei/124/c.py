# -*- coding: utf-8 -*-

N = input()

odd_list = N[0:len(N):2]
even_list = N[1:len(N):2]


def calc_one_and_zero(arr):
    zero_count = arr.count('0')
    one_count = arr.count('1')
    return zero_count, one_count


odd_zero,  odd_one = calc_one_and_zero(odd_list)
even_zero, even_one = calc_one_and_zero(even_list)

if odd_zero + even_one > odd_one + even_zero:
    print(odd_one + even_zero)
else:
    print(odd_zero + even_one)
