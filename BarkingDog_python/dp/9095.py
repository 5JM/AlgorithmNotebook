if __name__ == '__main__':
    # D[i]를 1,2,3의 합으로 나타내는 방법의 수
    # D[k] = D[k-1] + D[k-2] + D[k-3]
    
    # D[3] = 1+1+1, 1+2, 2+1, 3 = 4
    # D[2] = 1+1, 2 = 2
    # D[1] = 1 = 1
    
    D = [0] * 11
    D[1] = 1; D[2]=2; D[3]=4
    for i in range(4, 11):
        D[i] = D[i-3] + D[i-2] + D[i-1]

    T = int(input())

    arr = [int(input()) for _ in range(T)]
    
    for n in arr:
        print(D[n])