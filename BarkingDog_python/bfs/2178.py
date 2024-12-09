import sys
from collections import deque

N, M = 0, 0
BOARD = None

dx = [1, 0 ,-1, 0]
dy = [0, 1, 0, -1]

def bfs():
    for i in range(N):
        for j in range(M):
            if BOARD[i][j] == 0 or VIS[i][j]:
                continue

            Q = deque()
            Q.append([i, j])

            while len(Q):
                cur = Q.popleft()

                for dir in range(4):
                    nx = cur[0] + dx[dir]
                    ny = cur[1] + dy[dir]

                    if nx < 0 or nx >= N or ny < 0 or ny >= M:
                        continue

                    if BOARD[nx][ny] != 1:
                        continue
                    
                    if BOARD[nx][ny] == 1:
                        BOARD[nx][ny] = BOARD[cur[0]][cur[1]] + 1
                        Q.append([nx, ny])

    return BOARD[N-1][M-1]

if __name__ == '__main__':
    N, M = tuple(map(int, sys.stdin.readline().strip().split()))

    BOARD = [[0 for j in range(M)] for i in range(N)]
    VIS = BOARD.copy()

    for i in range(N):
        BOARD[i] = list(map(int , sys.stdin.readline().strip()))
    
    print(bfs())
