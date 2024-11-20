import sys

if __name__ == '__main__':
    N = int(input())

    queue = []
    result = []

    for _ in range(N):
        input_line_list = sys.stdin.readline().strip().split()

        command, value = input_line_list[0], None

        if len(input_line_list) > 1:
            value = input_line_list[1]

        if command == 'push':
            queue.append(value)
            
        elif command == 'pop':
            if len(queue) > 0:
                result.append(
                    queue[0]
                )

                queue.pop(0)

            else:
                result.append('-1')

        elif command == 'size':
            result.append(len(queue))
        
        elif command == 'empty':
            result.append('0' if len(queue) > 0 else '1')

        elif command == 'front':
            result.append(
                queue[0] if  len(queue) > 0  else '-1'
            )

        else:
            result.append(
                queue[-1] if  len(queue) > 0  else '-1'
            )

    print(*result, sep='\n')