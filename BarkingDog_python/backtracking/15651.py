from itertools import product

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))

    arr = [i for i in range(1, N+1)]

    for pair in list(product(arr, repeat = M)):
        print(*pair, end = ' ')
        print()
