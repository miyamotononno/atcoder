S = input()
K = int(input())


def main():
    count = 0

    for i in range(len(S)):
        if S[i] != '1':
            return S[i]

        count += 1
        if count == K:
            return '1'


print(main())
