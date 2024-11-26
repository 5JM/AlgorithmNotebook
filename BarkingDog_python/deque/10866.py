import sys
from collections import deque

if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    dq = deque()

    result = []

    for _ in range(N):
        cmd_list = sys.stdin.readline().strip().split()
        
        cmd = cmd_list[0]
        
        value = None

        if len(cmd_list) > 1:
            value = cmd_list[1]

        if cmd == 'push_front':
            dq.appendleft(value)

        elif cmd == 'push_back':
            dq.append(value)

        elif cmd == 'pop_front':
            result.append(dq.popleft() if len(dq) > 0 else -1)

        elif cmd == 'pop_back':
            result.append(dq.pop() if len(dq) > 0 else -1)

        elif cmd == 'size':
            result.append(len(dq))

        elif cmd == 'empty':
            result.append(0 if len(dq) > 0 else 1)

        elif cmd == 'front':
            result.append(dq[0] if len(dq) > 0 else -1 )
        else: # back
            result.append(dq[-1] if len(dq) > 0 else -1 )

    print(*result, sep='\n')