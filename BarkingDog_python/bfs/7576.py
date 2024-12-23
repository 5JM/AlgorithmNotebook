from collections import deque
import sys

N, M = 0, 0

BOARD = []

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs():
    global BOARD, N, M
    
    while len(Q):
        cur = Q.popleft()

        for dir in range(4):
            nx = cur[0] + dx[dir]
            ny = cur[1] + dy[dir]

            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            
            if BOARD[nx][ny] != 0:
                continue
            
            BOARD[nx][ny] = BOARD[cur[0]][cur[1]] + 1
            Q.append([nx, ny])

if __name__ == '__main__':
    M, N = tuple(map(int, sys.stdin.readline().strip().split()))
    RESULT = 0
    Q = deque()

    for _ in range(N):
        BOARD.append(
            list(map(int, sys.stdin.readline().strip().split()))
        )

    # 익은 토마토 위치 queue에 삽입
    for i in range(N):
        for j in range(M):
            if BOARD[i][j] == 1:
                Q.append([i, j])

    bfs()
    
    for i in range(N):
        for j in range(M):
            # 안익은 토마토가 있다면
            if BOARD[i][j] == 0:
                print(-1)
                exit()
            
            RESULT = max(RESULT, BOARD[i][j])

    print(RESULT-1)