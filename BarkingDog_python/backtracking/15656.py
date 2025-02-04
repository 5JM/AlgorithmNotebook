from itertools import product

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    arr = sorted(arr)

    for pair in list(product(arr, repeat = M)):
        print(*pair, end=' ')
        print()