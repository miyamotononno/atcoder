W, H, x, y = list(map(int, input().split()))

def calc():
    if x == W/2 and y ==H/2:
        return H*W/2, 1
    else:
        return H*W/2, 0

print(*calc())