import sys
from collections import deque

N, M = 0, 0
BOARD = None
VIS = None

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def vis_board():
    for i in range(N):
        for j in range(M):
            print(BOARD[i][j] , end=' ')
        print()

def bfs():
    '''
        inputs:
            None
        
        outputs:
            - num_pic: int, numbers of pictures on th\e board
            - max_area: int, max area among the pictures
    
    '''
    num_pic = 0
    max_area = 0

    for i in range(N):
        for j in range(M):
            if BOARD[i][j] == 0 or VIS[i][j]:
                continue

            num_pic+=1

            Q = deque()
            VIS[i][j] = 1
            Q.append([i, j])

            area = 0

            while len(Q):
                area+=1

                cur = Q.popleft()

                for dir in range(4):
                    nx = cur[0] + dx[dir]
                    ny = cur[1] + dy[dir]

                    if nx < 0 or nx >= N or ny < 0 or ny >= M:
                        continue
                    
                    if VIS[nx][ny] or BOARD[nx][ny] != 1:
                        continue
                    
                    VIS[nx][ny] = 1
                    Q.append([nx,ny])
            
            max_area = max(max_area, area)

    return num_pic, max_area


if __name__ == '__main__':
    N, M = tuple(map(int , sys.stdin.readline().strip().split()))

    BOARD = [[0 for j in range(M)] for i in range(N)]
    VIS = BOARD.copy()

    for i in range(N):
        BOARD[i] = list(map(int , sys.stdin.readline().strip().split()))
    

    num_pic, max_area = bfs()
    
    print(num_pic)
    print(max_area)