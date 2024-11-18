import sys

# https://redcubes.tistory.com/205

if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    
    nums = [ int(sys.stdin.readline().strip()) for _ in range(N) ]

    stack = []
    result = 0

    for i in range(N):
        cnt = 1
        while stack and stack[-1][0] <= nums[i] :
            top = stack.pop()
            result += top[1]
            
            if top[0] == nums[i]:
                cnt += top[1]
        
        if stack:
            result += 1

        stack.append([nums[i], cnt])
    
    print(result)