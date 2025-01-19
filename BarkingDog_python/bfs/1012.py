from collections import deque

BOARD, VIS = [], []
M,N,K = 0, 0, 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs():
    Q = deque()
    cnt = 0

    # find init pose
    for i in range(M):
        for j in range(N):

            if BOARD[i][j] and not VIS[i][j]:
                init_pose = [i, j]

                Q.append(init_pose)
                VIS[i][j] = 1

                cnt += 1

                while Q:
                    cur = Q.popleft()

                    for dir in range(4):
                        nx = cur[0] + dx[dir]
                        ny = cur[1] + dy[dir]
                        
                        if (nx < 0 or nx >= M ) or (ny < 0 or ny >= N):
                            continue
                        
                        if BOARD[nx][ny]!=1 or VIS[nx][ny] == 1:
                            continue

                        Q.append([nx, ny])
                        VIS[nx][ny] = 1

    return cnt


if __name__ == '__main__':
    T = int(input())
    RESULTS = []

    for _ in range(T):
        BOARD, VIS = [], []

        M, N, K = list(map(int, input().strip().split()))

        for _ in range(M):
            BOARD.append([0]*N)
            VIS.append([0]*N)
        
        for _ in range(K):
            x, y = list(map(int, input().strip().split()))

            BOARD[x][y] = 1
        
        RESULTS.append(bfs())

    print(*RESULTS, sep='\n')
