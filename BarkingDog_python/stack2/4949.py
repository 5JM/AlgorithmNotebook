import sys

def is_valid(str):
    stack = []

    for s in str:
        if s == '(' or s == '[' :
            stack.append(s)
        
        elif s == ')' or s == ']':
            if len(stack) == 0:
                return 'no'
            else:
                if s==')' and stack[-1] == '(':
                    del stack[-1]
                elif s==']' and stack[-1] == '[':
                    del stack[-1]
                
                else:
                    return 'no'
    
    return 'no' if len(stack) else 'yes'


if __name__ == '__main__':
    inputs = []

    while True:
        input_str = sys.stdin.readline()[:-1]
        
        if input_str == '.':
            break
        
        inputs.append(is_valid(input_str))
    print(*inputs, sep='\n')