from itertools import product

arr, is_used, answer = [], [], []
N, M = 0, 0

def backtracking(k):
    if k == M:
        for i in range(M):
            print(answer[i], end=' ')
        print()
        return
    
    tmp = 0
    for i in range(N):
        if is_used[i]:# or arr[i] == tmp:
            continue

        is_used[i] = 1
        answer[k] = arr[i]
        tmp = arr[i]

        backtracking(k+1)
        is_used[i] = 0

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    arr = set(arr)
    arr = sorted(arr)

    for pair in list(product(arr, repeat = M)):
        print(*pair, end=' ')
        print()
