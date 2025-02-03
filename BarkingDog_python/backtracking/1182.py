from itertools import combinations as comb

N, S = 0, 0
cnt = 0

def sub_permutation_sum(arr):
    global cnt

    for i in range(1, N + 1):
        for combinations in list(comb(arr, i)):
            if sum(combinations) == S:
                cnt += 1

if __name__ == '__main__':
    N, S = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))

    sub_permutation_sum(arr)

    print(cnt)