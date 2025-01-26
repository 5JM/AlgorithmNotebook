def hanoi(N, start, end):
    if N == 1:
        print(start, end)
        return
    
    X  = 6 - start - end

    hanoi(N-1, start, X) # step 1 : start 기둥의 n-1개의 원판을 x 기둥에

    print(start, end) # step 2: start 기둥의 가장 큰 원판을 3기둥에

    hanoi(N-1, X, end) # step 3 : x 기둥의 n-1개의 원판을 end 기둥에

if __name__ == '__main__':
    N = int(input())

    print(2**N-1)

    hanoi(N, 1, 3)
