def in_func():
    return list(map(int, input().strip().split()))

if __name__ == '__main__':
    '''
        D[k]는 A[1]~A[k]구간의 합
        D[k] = D[k-1]+A[k]
        D[0] = 0

        A[i]+A[i+1]+...+A[j]
        = (A[1]+A[2]+..+A[j]) - (A[1]+A[2]+..+A[i-1])
        = D[j]-D[i-1]
    '''
    D = [0] * 100_001
    ARR = [0] * 100_001
    result = []
    
    N, M = in_func()
    ARR[1:N+2] = in_func()

    for i in range(1, N + 1):
        D[i] = D[i-1] + ARR[i]
    
    for i in range(M):
        i, j = in_func()
        result.append(D[j] - D[i-1])

    print(*result, sep='\n')