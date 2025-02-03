is_used_0 = [0]*40 # 열
is_used_1 = [0]*40 # 대각선 /
is_used_2 = [0]*40 # 대각선 \

N, cnt = 0, 0 

def NQueen(X):
    global cnt, is_used_0, is_used_1, is_used_2

    if X == N:
        cnt += 1
        return
    
    for y in range(0, N):
        if is_used_0[y] or is_used_1[X + y] or is_used_2[X - y + N - 1]:
            continue

        is_used_0[y] = 1 # 같은 열 제외
        is_used_1[X + y] = 1 # \ 대각선 제외
        is_used_2[X - y + N - 1] = 1 # / 대각선 제외

        NQueen(X+1)

        is_used_0[y] = 0
        is_used_1[X + y] = 0
        is_used_2[X - y + N - 1] = 0

if __name__ == '__main__':
    N = int(input())
    
    NQueen(0)

    print(cnt)