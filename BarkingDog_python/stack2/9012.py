import sys

def is_valid(str):
    '''
    - problem
            - 문자열에 포함되는 괄호는 소괄호("()")
            - 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
            - 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
            - 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
            - 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
            
        - input: str
            - 소괄호("( )")로 이루어져 있음 
            

        - output: str, 'yes' or 'no'
            - return 'yes' if 균형잡힌 문자열 
    
    '''
    stack = []

    for s in str:
        if s == '(' or s == '[' :
            stack.append(s)
        
        elif s == ')' or s == ']':
            if len(stack) == 0:
                return 'NO'
            else:
                if s==')' and stack[-1] == '(':
                    del stack[-1]
                elif s==']' and stack[-1] == '[':
                    del stack[-1]
                
                else:
                    return 'NO'
    
    return 'NO' if len(stack) else 'YES'


if __name__ == '__main__':
    N = int(input())
    
    results = []

    for _ in range(N):
        input_str = sys.stdin.readline().strip()
        
        results.append(is_valid(input_str))
    print(*results, sep='\n')