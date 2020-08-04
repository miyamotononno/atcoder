import collections

c = collections.Counter

n = int(input())
v = list(map(int, input().split()))

even_v = [v[i] for i in range(n) if i % 2 == 0]
odd_v = [v[i] for i in range(n) if i % 2 == 1]

c1 = c(even_v).most_common(2)
c2 = c(odd_v).most_common(2)


def calc(x, y):
    return len(even_v) - x[1] + len(odd_v) - y[1]


def main():
    if c1[0] != c2[0]:
        return calc(c1[0], c2[0])

    if len(c1) == 1 and len(c2) == 1:
        return len(odd_v)

    if calc(c1[0], c2[1]) < calc(c1[1], c2[0]):
        return calc(c1[0], c2[1])
    else:
        return calc(c1[1], c2[0])


print(main())
