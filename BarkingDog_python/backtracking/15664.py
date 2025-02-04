arr, is_used, result = [], [], []
N, M = 0, 0

def backtracking(k, start_idx):
    global is_used, result

    if k == M:
        for i in range(M):
            print(result[i], end=' ')
        print()
        return

    tmp = 0
    for i in range(start_idx, N):
        if is_used[i] or arr[i] == tmp:
            continue

        is_used[i] = 1
        result[k] = arr[i]
        tmp = arr[i]

        backtracking(k+1, i + 1)
        is_used[i] = 0

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    arr = sorted(arr)

    is_used = [0] * N
    result = [0] * N

    backtracking(0)