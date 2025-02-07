
D = [0] * 1_000_001

if __name__ == '__main__':
    # D[k] = D[k/3]+1
    # D[k] = D[k/2]+1
    # D[k] = D[k-1]+1
    # D[1] = 0

    X = int(input())

    D[1] = 0

    for i in range(2, X+1):
        D[i] = D[i-1]+1

        if i % 2 ==0:
            D[i] = min(D[i], D[i//2]+1)

        if i % 3 ==0:
            D[i] = min(D[i], D[i//3]+1)
    print(D[X])