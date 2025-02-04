from itertools import combinations_with_replacement

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    arr = sorted(arr)

    for pair in list(combinations_with_replacement(arr, M)):
        print(*pair, end=' ')
        print()