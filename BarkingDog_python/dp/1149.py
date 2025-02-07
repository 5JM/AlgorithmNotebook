if __name__ == '__main__':
    '''
    D[k]는 아래의 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값
    D[k][0] k번째 집까지 칠하는 비용의 최소값, 이때 k의 집은 빨강
    D[k][1] k번째 집까지 칠하는 비용의 최소값, 이때 k의 집은 초록
    D[k][2] k번째 집까지 칠하는 비용의 최소값, 이때 k의 집은 파랑
    
    R[k] k번째 집을 집을 빨강색으로 칠할 때 드는 비용
    D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k]
    D[k][1] = min(D[k-1][0], D[k-1][2]) + G[k]
    D[k][2] = min(D[k-1][0], D[k-1][1]) + B[k]

    D[1][0] = R[1]
    D[1][1] = G[1]
    D[1][2] = B[1]
    '''

    
    R = [0] * 1001
    G = [0] * 1001
    B = [0] * 1001

    D = []
    for _ in range(1001):
        D.append([0,0,0])

    N = int(input())

    for i in range(1, N+1):
        R[i], G[i], B[i] = list(map(int, input().strip().split()))

    D[1][0] = R[1]
    D[1][1] = G[1]
    D[1][2] = B[1]

    for i in range(2, N+1):
        D[i][0] = min(D[i-1][1], D[i-1][2]) + R[i]
        D[i][1] = min(D[i-1][0], D[i-1][2]) + G[i]
        D[i][2] = min(D[i-1][0], D[i-1][1]) + B[i]
    
    print(min(*D[N]))

