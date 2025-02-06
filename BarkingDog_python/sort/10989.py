import sys

if __name__ == '__main__':
    # 계수정렬
    n = int(sys.stdin.readline())
    arr = [0] * 10001 

    for _ in range(n):
        arr[int(sys.stdin.readline())] += 1

    for i in range(len(arr)):
        if arr[i] == 0:
            continue
        # 중복된 수
        for _ in range(arr[i]):
            print(i)