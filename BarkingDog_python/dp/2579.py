if __name__ == '__main__':
    # D[i][j]는 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올랐을 때
    # 점수 합의 최대값, 단 i번째 계단은 반드시 밟아야함

    # j = 1, 2
    # D[i][1] = max(D[i-2][1], D[i-2][2]) + S[i]
    # D[i][2] = D[i-1][1] + S[i]

    # D[1][1]
    # D[1][2]
    # D[2][1] 
    # D[2][1]

    D = [[0,0,0] for _ in range(302)]
    STEPS = [0]*301
    N = int(input())

    for i in range(1, N+1):
        STEPS[i] = int(input())
    
    if N == 1:
        print(STEPS[1])
        exit()
    
    D[1][1] = STEPS[1]
    D[1][2] = 0
    D[2][1] = STEPS[2]
    D[2][2] = STEPS[1] + STEPS[2]

    for i in range(3, N+1):
        D[i][1] = max(D[i-2][1], D[i-2][2]) + STEPS[i]
        D[i][2] = D[i-1][1] + STEPS[i]

    # 마지막 계단을 반드시 밟아야함
    print(max(D[N][1], D[N][2]))