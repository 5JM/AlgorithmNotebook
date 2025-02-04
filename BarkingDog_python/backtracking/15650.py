from itertools import combinations

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))

    arr = [i for i in range(1, N+1)]

    for pair in list(combinations(arr, M)):
        print(*pair, end=' ')
        print()
