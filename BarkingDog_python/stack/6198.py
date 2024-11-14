import sys

if __name__ == '__main__':
    N = int(input())
    heights = [int(sys.stdin.readline().strip()) for _ in range(N)]
    
    stack = []
    cnt = 0

    for cur_h in heights:
        while stack and stack[-1] <= cur_h:
            stack.pop()
        
        cnt += len(stack)
        stack.append(cur_h)
        
    print(cnt)