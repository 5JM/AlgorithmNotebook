import sys

if __name__ == '__main__':
    N = int(input())
    
    list_tower = list(map(int, sys.stdin.readline().strip().split()))
    receive = [0]*N
    stack = []

    # 1. tower를 앞에서부터 
    for i in range(N):
        # 2. stack에 값이 존재한다면
        while stack:
            # 2-1. stack의 tower와 현재 tower의 높이를 비교
            #   stack의 tower가 현재 tower의 높이보다 크다면 -> 수신 가능
            if stack[-1][1] > list_tower[i]:
                receive[i] = stack[-1][0] + 1
                break
            #   stack의 tower가 현재 tower의 높이보다 작다면 -> 수신 불가
            #   stack의 tower를 pop한 뒤, 그 다음 stack의 tower와 비교
            else:
                stack.pop()

        # 3. 신호를 받은 top을 찾았거나 stack이 비었다면 현재 tower를 stack에 추가
        stack.append([i, list_tower[i]])

    print(*receive)