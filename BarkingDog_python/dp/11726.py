if __name__ == '__main__':
    '''
    D[i] = 2xn 크기의 직사각형을 채우는 방법의 수

    D[k] = D[k-1] + D[k-2]
    D[1] = 1
    D[2] = 2
    '''
    D = [0] * 1001
    D[1] = 1
    D[2] = 2

    N = int(input())

    for i in range(3, N+1):
        D[i] = (D[i-1] + D[i-2]) % 10007
    
    print(D[N])