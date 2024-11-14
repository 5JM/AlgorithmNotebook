import sys

if __name__ == '__main__':
    N = int(input())
    nums = list(map(int, sys.stdin.readline().strip().split()))

    stack, result = [0], [-1]*N

    for i in range(1, N):
        while stack and nums[stack[-1]] < nums[i]:
            result[stack.pop()] = nums[i]

        stack.append(i)
            
    print(*result)