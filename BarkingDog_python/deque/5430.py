import sys
from collections import deque

def func5430(functions, n, arr):
    dq = deque()

    reverse = False

    result = ''

    for i in arr:
        dq.append(i)

    for cmd in functions:
        if cmd == 'R':
            reverse = not reverse
        else:
            if reverse:
                dq.pop()
                
            else:
                dq.popleft()
    
    while dq:
        val = dq.pop() if reverse else dq.popleft()
        result+=f'{val}'
        result+=','
    
    return '['+result[:-1]+']'

if __name__ == '__main__':
    TEST_CASE = int(sys.stdin.readline().strip())
    RESULT = []

    for _ in range(TEST_CASE):
        FUNCTIONS = sys.stdin.readline().strip()
        N = int(sys.stdin.readline().strip())
        
        try:
            ARR = list(map(int, sys.stdin.readline().strip()[1:-1].split(',')))
        except Exception:
            ARR = []

        try:
            RESULT.append(func5430(FUNCTIONS, N, ARR))
        except Exception:
            RESULT.append('error')
    
    print(*RESULT, sep='\n')
