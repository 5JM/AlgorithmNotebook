import sys
from collections import deque

if __name__ == '__main__':
    N, L = list(map(int, sys.stdin.readline().strip().split()))

    a_list = list(map(int, sys.stdin.readline().strip().split()))

    results = []

    dq = deque()

    for i in range(N):
        
        if dq:
            if dq[0][0] < i - L + 1:
                dq.popleft()

            '''
            현재 값이 deque back보다 작으면,
            해당 back 값은 앞으로 최소값이 될 수 없으므로 pop
            '''
            while dq and dq[-1][1] > a_list[i]:
                dq.pop()

        dq.append([i, a_list[i]])
        results.append(dq[0][1])
        
    print(*results, sep=' ')




