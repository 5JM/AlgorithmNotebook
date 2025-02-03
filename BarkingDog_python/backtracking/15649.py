
N, M = 0,0
arr = [0] * 10
is_used = [0] * 10

def backtracking(k): # 현재 k 개를 골랐음
    if k == M:
        for i in range(M):
            print(arr[i], end = ' ')
        print()
        return
    
    for i in range(1, N+1):
        if not is_used[i]:
            arr[k] = i
            is_used[i] = 1
            backtracking(k + 1)
            is_used[i] = 0


if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))

    backtracking(0)
