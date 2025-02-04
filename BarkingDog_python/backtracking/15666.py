arr, answer = [], []
N, M = 0, 0

def backtracking(k, start_idx):
    if k == M:
        for i in range(M):
            print(answer[i], end=' ')
        print()
        return

    tmp = 0
    for i in range(start_idx, N):
        if arr[i]==tmp:
            continue

        answer[k] = arr[i]
        tmp = arr[i]

        backtracking(k+1, i)

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))

    arr = sorted(arr)

    answer = [0]*N

    backtracking(0, 0)