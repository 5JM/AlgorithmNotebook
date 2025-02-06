import sys

if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())

    arr = []
    for _ in range(N):
        arr.append(int(sys.stdin.readline().strip()))

    arr.sort()

    print(*arr, sep='\n')