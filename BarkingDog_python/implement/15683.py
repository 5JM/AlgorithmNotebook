import copy

BOARD, RESULT_BOARD = [], []
N, M = 0, 0

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def UPD(x, y, dir):
    dir %= 4

    while True:
        x += dx[dir]
        y += dy[dir]

        if (x < 0 or x >= N or y < 0 or y >= M) or RESULT_BOARD[x][y] == 6:
            return
        
        if RESULT_BOARD[x][y] != 0:
            continue

        RESULT_BOARD[x][y] = 7

if __name__ == '__main__':
    N, M = list(map(int, input().strip().split()))
    AREA = 0
    CCTV_COORD = []

    for _ in range(N):
        BOARD.append(
            list(map(int, input().strip().split()))
        )
    for i in range(N):
        for j in range(M):
            item = BOARD[i][j]
            if item != 0 and item != 6:
                CCTV_COORD.append([i, j])
            
            if item == 0:
                AREA += 1

    # 각 cctv는 4방향을 가질 수 있다고 가정
    # k개의 cctv는 4 ^ k - 1의 방향을 가질 수 있음
    for tmp in range(4**len(CCTV_COORD)):
        RESULT_BOARD = copy.deepcopy(BOARD)
        cctv_dir = tmp

        for i in range(len(CCTV_COORD)):
            dir = cctv_dir % 4

            cctv_dir //= 4

            x, y = CCTV_COORD[i]

            item = BOARD[x][y]
            if item == 1:
                UPD(x, y, dir)

            elif item == 2:
                UPD(x, y, dir)
                UPD(x, y, dir+2)

            elif item == 3:
                UPD(x, y, dir)
                UPD(x, y, dir+1)

            elif item == 4:
                UPD(x, y, dir)
                UPD(x, y, dir+1)
                UPD(x, y, dir+2)

            else:
                UPD(x, y, dir)
                UPD(x, y, dir+1)
                UPD(x, y, dir+2)
                UPD(x, y, dir+3)
        # end of for loop len(cctv_coord)
        
        val = 0
        for i in range(N):
            for j in range(M):
                if RESULT_BOARD[i][j] == 0:
                    val += 1
        AREA = min(AREA, val)
    
    print(AREA)
