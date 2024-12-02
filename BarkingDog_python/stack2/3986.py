import sys

def is_good_word(str):
    '''
    - problem
            - 단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다. 
            - 만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른 위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다. 
            - 평석이가 '좋은 단어' 개수를 세는 것을 도와주자.
            
            -> 'A' 혹은 'B'가 괄호처럼 올바르게 짝지어 진 갯수를 구하자
            
        - input: str
            - A와 B로만 이루어진 단어
            - 길이는 2와 100,000사이

        - output: Boolean
            - return True if '좋은 단어'
    
    '''

    stack = []

    for s in str:
        if len(stack) == 0:
            stack.append(s)
            continue
        
        if stack[-1] == s:
            del stack[-1]
        
        else:
            stack.append(s)
    
    return False if len(stack) else True


if __name__ == '__main__':
    N = int(input())

    result = []

    for _ in range(N):
        result.append(
            is_good_word( sys.stdin.readline().strip() )
        )
    
    print(sum(result))