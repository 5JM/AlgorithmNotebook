from collections import deque

if __name__ == '__main__':
    N, K = tuple(map(int, input().strip().split()))
    VIS = [0] * 100_001

    RESULT = 0
    
    Q = deque()
    Q.append(N)
    while Q:
        cur = Q.popleft()

        if cur == K:
            RESULT = VIS[cur]
            break 

        for i in [cur + 1, cur - 1, cur * 2]:
            if (0 <= i <= 100_000) and not VIS[i]: 
                VIS[i] = VIS[cur] + 1
                Q.append(i)

    print(RESULT)