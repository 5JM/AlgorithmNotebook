from collections import deque
import sys

N = 0
BOARD, VIS = [], []

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(item:list):
    init()

    cnt = 0

    Q = deque()

    for i in range(N):
        for j in range(N):
            if (BOARD[i][j] in item) and not VIS[i][j]:
                Q.append([i, j])
                VIS[i][j] = 1

                cnt += 1
                
                while Q:
                    cur_x, cur_y = Q.popleft()

                    for dir in range(4):
                        nx = cur_x + dx[dir]
                        ny = cur_y + dy[dir]

                        if nx < 0 or nx >= N or ny < 0 or ny >= N:
                            continue

                        if not (BOARD[nx][ny] in item) or VIS[nx][ny]:
                            continue

                        Q.append([nx, ny])
                        VIS[nx][ny] = 1

    return cnt

def init():
    global VIS

    VIS = []

    for _ in range(N):
        VIS.append([0]*N)

if __name__ == '__main__':
    N = int(input())

    for _ in range(N):
        BOARD.append(
            list(sys.stdin.readline().strip())
        )
        VIS.append([0]*N)

    normal = [bfs(value) for value in [['R'], ['G'], ['B']]]
    juckrok = [bfs(value) for value in [['R', 'G'], ['B']]]
    
    print(f'{sum(normal)} {sum(juckrok)}')