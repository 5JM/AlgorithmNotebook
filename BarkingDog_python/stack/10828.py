import sys

def func10828(command_list):
    '''
        - problem 
            - 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
                명령은 총 다섯 가지이다.

                push X: 정수 X를 스택에 넣는 연산이다.
                pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
                size: 스택에 들어있는 정수의 개수를 출력한다.
                empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
                top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        
        - input
            - command_list: command string list (with space)

        - output
            - None
    '''
    stack = []
    top = -1
    
    for _command in command_list:
        tmp = _command.split()
        command = tmp[0]
        value = None

        if len(tmp) > 1:
            value = tmp[1]
            
        if command == 'push':
            stack.append(value)
            top += 1

        elif command == 'pop':
            if top >= 0: 
                print(stack[top])

                del stack[-1]

                top -= 1

            else:
                print(-1)
            
        elif command == 'size':
            print(top+1)
        
        elif command == 'empty':
            print(1 if top == -1 else 0)
        
        else: # top
            print(-1 if top == -1 else stack[-1])

if __name__ == '__main__':
    N = int(sys.stdin.readline().rstrip())
    command_list = []

    for _ in range(N):
        command = sys.stdin.readline().rstrip()

        command_list.append(command)

    func10828(command_list)