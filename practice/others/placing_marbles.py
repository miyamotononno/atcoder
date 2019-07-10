# -*- coding: utf-8 -*-

a = input()
b = 0
for i in range(len(a)):
    if a[i] == '1':
        b += 1

print(b)
