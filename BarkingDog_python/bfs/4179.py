from collections import deque

R, C = 0, 0

BOARD = []
J = []
FIRE = []

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(obj, Q):
    while len(Q):
        cur_x, cur_y = Q.popleft()

        for dir in range(4):
            nx = cur_x + dx[dir]
            ny = cur_y + dy[dir]

            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                continue

            if BOARD[nx][ny] == '#' or BOARD[nx][ny] == 'F':
                continue

            if obj[nx][ny] == -1:
                obj[nx][ny] = obj[cur_x][cur_y] + 1
                Q.append([nx, ny])
    
    return obj

if __name__ == '__main__':
    R, C = list(map(int, input().split()))
    start = [0,0]

    for i in range(R):
        BOARD.append(list(input().strip()))
        
        J.append([-1]*C)
        FIRE.append([-1]*C)

    Q = deque()
    # jihoon 초기 위치 설정
    for i in range(R):
        for j in range(C):
            if BOARD[i][j] == 'J':
                Q.append([i, j])
                J[i][j] = 0
    
    J = bfs(J, Q)

    Q = deque()
    # Fire 초기 위치 설정
    for i in range(R):
        for j in range(C):
            if BOARD[i][j] == 'F':
                Q.append([i, j])
                FIRE[i][j] = 0

    FIRE = bfs(FIRE, Q)

    # 최단 시간 계산
    min_time = 2000

    for i in range(R):
        for j in range(C):
            # jihoon이 가장자리에 도달
            if (i == 0 or i == R-1 or j == 0 or j == C-1) and J[i][j] != -1:
                if J[i][j] < FIRE[i][j] or FIRE[i][j] == -1:
                    min_time = min(min_time, J[i][j])

    print(min_time + 1 if min_time != 2000 else 'IMPOSSIBLE')