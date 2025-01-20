from collections import deque

BOARD = []

dx = [1, 0, 0, -1, 0, 0]
dy = [0, 1, 0, 0, -1, 0]
dz = [0, 0, 1, 0, 0, -1]

def bfs():
    global BOARD
    # BOARD shape = H, N, M
    
    while Q:
        # z, y, x
        cur = Q.popleft() 

        for dir in range(6):
            nz = cur[0] + dz[dir]
            ny = cur[1] + dy[dir]
            nx = cur[2] + dx[dir]

            if nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H:
                continue

            if BOARD[nz][ny][nx] != 0:
                continue

            BOARD[nz][ny][nx] = BOARD[cur[0]][cur[1]][cur[2]] + 1
            Q.append([nz, ny, nx])

if __name__ == '__main__':

    M, N, H = list(map(int, input().strip().split()))
    RESULT = 0

    Q = deque()

    for _ in range(H):
        tmp = []
        for _ in range(N):
            tmp.append(
                list(map(int,input().strip().split()))
            )
        
        BOARD.append(tmp)
    
    for z in range(H):
        for j in range(N):
            for i in range(M):
                if BOARD[z][j][i] == 1:
                    Q.append([z, j, i])

    bfs()
    
    # 익지 않은 토마토가 있다면
    for z in range(H):
        for j in range(N):
            for i in range(M):
                if BOARD[z][j][i] == 0:
                    print(-1)
                    exit()

                RESULT = max(RESULT, BOARD[z][j][i])

    print(RESULT-1)
