import sys, math

def func1475(num: str):
    """
        - problem
            - 다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
                다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
                다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
        
        - input: str
            - 첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.
            
        - output: str
            - 첫째 줄에 필요한 세트의 개수를 출력한다.
    """
    result = 0
    num_list = [0]*10

    for i in num:
        num_list[int(i)] += 1

    num_list[6] = math.ceil((num_list[6] + num_list[9])/2)

    return max(num_list[:-1])

if __name__ == '__main__':
    print(
        func1475(sys.stdin.readline().rstrip())
    )