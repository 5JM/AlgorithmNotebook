from itertools import permutations

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    arr = sorted(arr)
    
    for pair in list(permutations(arr, M)):
        print(*pair, end=' ')
        print()


