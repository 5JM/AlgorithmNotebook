from itertools import combinations_with_replacement

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))

    arr = [i for i in range(1, N+1)]

    for pair in list(combinations_with_replacement(arr, M)):
        print(*pair, end = ' ')
        print()