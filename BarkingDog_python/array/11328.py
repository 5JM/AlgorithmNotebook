import sys

def func11328(str_a, str_b):
    '''
        - problem
            - 두 개의 문자열에 대해, 2번째 문자열이 무작위로 재배열하여 1번째 문자열을 만들 수 있는지 판단하라.
                여기에서 입력된 문자열과 새로 재배열된 문자열이 다를 필요는 없다.
        - input
            - 입력의 첫 번째 줄은 테스트 케이스의 수 0 < N < 1001 이다.
                각각의 테스트 케이스는 하나의 줄에 영어 소문자들로만 이루어진 
                두 개의 문자열이 한 개의 공백으로 구분되어 주어진다. 
                각각의 문자열의 길이는 최대 1000 이다.
        
        - output
            - 각각의 테스트 케이스에 대해, 2번째 문자열이 재배열되어 1번째 문자열을 얻어질 수 있는지의 여부를 
                "Impossible"(불가능) 또는 "Possible"(가능)으로 나타내시오. 
                (따옴표는 제외하고 출력한다.)
    '''

    alphabets_a, alphabets_b = [0] * 26 , [0] * 26 

    for s_a, s_b in zip(str_a, str_b):
        alphabets_a[ord(s_a) - 97] += 1
        alphabets_b[ord(s_b) - 97] += 1

    if alphabets_a == alphabets_b:
        return 'Possible'
    else:
        return 'Impossible'

if __name__ == '__main__':
    N = int(input())

    result = ''
    for _ in range(N):
        str_a, str_b = tuple(map(str, input().split()))

        result+=func11328(str_a, str_b)
        result+='\n'

    print(result)