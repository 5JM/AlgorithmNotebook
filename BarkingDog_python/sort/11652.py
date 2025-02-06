import sys

if __name__ == '__main__':
    cnt, max_cnt = 0, 0
    max_val, prev = -2^62-1, -2^62-1

    N = int(input())
    arr = [int(sys.stdin.readline().strip()) for _ in range(N)]

    arr.sort()

    for i, val in enumerate(arr):
        if i==0 or val == prev:
            cnt+=1
        else:
            if cnt > max_cnt:
                max_cnt = cnt
                max_val = prev

            cnt = 1
        
        prev = val

    if cnt > max_cnt:
        max_val = arr[-1]

    print(max_val)