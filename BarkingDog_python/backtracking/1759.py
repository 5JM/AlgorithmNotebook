arr, answer = [], []
L, C = 0, 0

def backtracking(k, start_idx):
    global answer

    if k == L:
        jaeum, moeum = 0, 0
        for i in range(L):
            if answer[i] in ['a', 'e', 'i', 'o', 'u']:
                moeum += 1
            else:
                jaeum += 1
            
        if moeum >= 1 and jaeum >= 2:
            print(*answer, sep='')
            
        return
    
    for i in range(start_idx, C):
        answer.append(arr[i])

        backtracking(k+1, i + 1)

        answer.pop()

if __name__ == '__main__':
    L, C = list(map(int, input().strip().split()))
    arr = list(input().strip().split())
    arr =sorted(arr)
    
    backtracking(0, 0)