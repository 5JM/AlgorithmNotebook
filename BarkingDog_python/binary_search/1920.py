import sys

ARR = []
N = 0

def binary_search(target):
    start_idx, end_idx = 0, N-1

    while start_idx <= end_idx:
        mid = (start_idx + end_idx)//2

        if ARR[mid] < target:
            start_idx = mid+1

        elif ARR[mid] > target:
            end_idx = mid-1

        else: # find
            return 1
    return 0


if __name__ == '__main__':
    N = int(input())
    ARR = list(map(int, sys.stdin.readline().strip().split()))
    M = int(input())
    TARGETS = list(map(int, sys.stdin.readline().strip().split()))

    ARR.sort()

    for target in TARGETS:
        print(binary_search(target))