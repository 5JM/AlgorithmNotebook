import sys
from collections import deque

if __name__ == '__main__':
    N, M = list(map(int, sys.stdin.readline().strip().split()))

    targets = list(map(int, sys.stdin.readline().strip().split()))
    target_idx = 0

    cnt = 0

    dq = deque()
    
    for i in range(1, N+1):
        dq.append(i)

    while target_idx != M:

        to_find_index = dq.index(targets[target_idx])
        
        if to_find_index == 0:
            dq.popleft()
            target_idx += 1

            continue
        
        to_move = -to_find_index if to_find_index <= len(dq) - to_find_index else len(dq) - to_find_index
        
        dq.rotate(to_move)
        
        cnt += abs(to_move)

    print(cnt)