arr, result, is_used = [], [], []
N, M = 0, 0

def backtracking(k):
    global is_used, result

    if k == M:
        for i in range(M):
            print(result[i], end = ' ')
        print()
        return
    
    tmp = 0

    for i in range(N):
        if is_used[i] or arr[i]==tmp:
            continue
        result[k] = arr[i]

        is_used[i] = 1
        tmp = arr[i]

        backtracking(k+1)

        is_used[i] = 0

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    
    arr = sorted(arr)
    result = [0] * N
    is_used = [0] * N

    backtracking(0)