import sys

def func10808(input: str)->str:
    """
        - problem
            - 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
            - 단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.
        - input: str
            - word ( str, length <= 100, small letter )
        - output: str
            - alphabet count str
    """
    alphabat_list = [0] * 26
    for input_alphabat in input:
        index = ord(input_alphabat) - ord('a')
        alphabat_list[index]+=1

    return ' '.join(list(map(str, alphabat_list))) 

if __name__ == '__main__':
    
    input = sys.stdin.readline().rstrip()

    print(func10808(input))