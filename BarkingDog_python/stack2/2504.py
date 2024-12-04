import sys

if __name__ == '__main__':
    string = sys.stdin.readline().strip()

    stack = []
    prev = None

    result, tmp = 0, 1

    for s in string:
        if s == '(':
            stack.append(s)
            tmp *= 2

        elif s== '[':
            stack.append(s)
            tmp *= 3

        elif s== ')':
            if len(stack) and stack[-1] == '(': # valid stack condition
                if prev == '(': # check ()
                    result += tmp
                tmp //= 2

                del stack[-1]

            else:
                result = 0
                break

        else:
            if len(stack) and stack[-1] == '[': # valid stack condition
                if prev == '[': # check []
                    result += tmp
                tmp //= 3

                del stack[-1]

            else:
                result = 0
                break

        prev = s

    print(0 if len(stack) else result)