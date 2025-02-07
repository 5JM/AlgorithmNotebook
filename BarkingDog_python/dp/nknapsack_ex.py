
def knapsack(N, K, ITEMS):
    '''
    D[i][w]는 i번째까지의 물건을 고려했을 때 무게 w이하에서 얻을 수 있는 최대 가치

    # i번째 물건 선택 x
    D[i][w] = D[i-1][w]
    
    # i번째 물건 선택 o
    D[i][w] = max(D[i-1][w], D[i-1][w-w[i]] + v[i]) 
    '''

    D = [[0]*(K+1) for _ in range(N+1)]

    for i in range(1, N+1):
        weight, value = ITEMS[i-1]

        for w in range(K+1):
            # 현재 물건을 배낭에 담을 수 없을 때
            if weight > w: 
                D[i][w] = D[i-1][w]
            else:
                D[i][w] = max(D[i-1][w], D[i-1][w-weight] + value)
    
    return D[N][K]  # 배낭 용량 K일 때, 얻을 수 있는 최대 가치

if __name__ == '__main__':
    '''
    Q) 물건의 갯수 N과 가방의 용량 K가 주어졌을 때,
        최대 용량이 초과하지 않는 범위에서 선택한 물건의 가치 합을 최대로 만들어라

        첫번째 줄에는 N, K
        두번째 줄부터는 N개의 물건 정보가 무게와 가치 순으로 입력된다

        ex) 
        4 5
        2 3
        1 2
        3 4
        2 2

        ans) 7 

    '''
    N, K = list(map(int, input().strip().split()))
    # W = [0]*N
    # V = [0]*N
    ITEMS = []

    for i in range(N):
        w, v = list(map(int, input().strip().split()))
        ITEMS.append([w, v])

    print(knapsack(N, K, ITEMS))