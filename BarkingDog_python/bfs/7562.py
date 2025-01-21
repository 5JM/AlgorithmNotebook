from collections import deque

BOARD = []

dx = [1, 2,  2,  1, -1, -2, -2, -1]
dy = [2, 1, -1, -2, -2, -1,  1,  2]

def bfs(start_pos, target_pos):
    global BOARD

    q = deque()
    q.append(start_pos)

    while q:
        cur = q.popleft()
        
        if cur == target_pos:
            return BOARD[cur[0]][cur[1]]-1

        for dir in range(8):
            nx = cur[0] + dx[dir]
            ny = cur[1] + dy[dir]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue

            if BOARD[nx][ny] != 0:
                continue

            BOARD[nx][ny] = BOARD[cur[0]][cur[1]] + 1
            q.append([nx, ny])
    

if __name__ == '__main__':
    T = int(input())
    RESULTS = []

    for _ in range(T):
        BOARD = []

        N = int(input())
        start_pos = list(map(int, input().strip().split()))
        target_pos = list(map(int, input().strip().split()))
        
        for i in range(N):
            BOARD.append([0]*N)

        for i in range(N):
            for j in range(N):
                if [i, j] == start_pos:
                    BOARD[i][j] = 1

        RESULTS.append(
            bfs(start_pos, target_pos)
        )

    print(*RESULTS, end='\n')

