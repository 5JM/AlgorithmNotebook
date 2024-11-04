import sys, math

def func13300(K, male_list, female_list):
    """
        - params
            - K: 한 방의 최대 인원수
            - male_list: 남학생 학년별 인원 list
            - female_list: 여학생 학년별 인원 list
        - output
            - 학생들을 모두 배정하기 위해 필요한 최소한의 방의 수를 출력한다.
    """
    cnt = 0
    
    for grade in range(6):
        
        if male_list[grade] > 0:
            cnt += math.ceil(male_list[grade] / K)

        if female_list[grade] > 0:
            cnt += math.ceil(female_list[grade] / K)

    return cnt

if __name__ == '__main__':
    """
        - problem
            - 남학생은 남학생끼리, 여학생은 여학생끼리 방을 배정해야 한다. 또한 한 방에는 같은 학년의 학생들을 배정해야 한다. 물론 한 방에 한 명만 배정하는 것도 가능하다.
                한 방에 배정할 수 있는 최대 인원 수 K가 주어졌을 때, 조건에 맞게 모든 학생을 배정하기 위해 필요한 방의 최소 개수를 구하는 프로그램을 작성하시오.
                예를 들어, 수학여행을 가는 학생이 다음과 같고 K = 2일 때 12개의 방이 필요하다. 왜냐하면 3학년 남학생을 배정하기 위해 방 두 개가 필요하고 
                4학년 여학생에는 방을 배정하지 않아도 되기 때문이다.

        - input
            - 표준 입력으로 다음 정보가 주어진다. 
                첫 번째 줄에는 수학여행에 참가하는 학생 수를 나타내는 정수 N(1 ≤ N ≤ 1,000)과 
                한 방에 배정할 수 있는 최대 인원 수 K(1 < K ≤ 1,000)가 공백으로 분리되어 주어진다. 
                다음 N 개의 각 줄에는 학생의 성별 S와 학년 Y(1 ≤ Y ≤ 6)가 공백으로 분리되어 주어진다. 
                성별 S는 0, 1중 하나로서 여학생인 경우에 0, 남학생인 경우에 1로 나타낸다. 

        - output
            - 표준 출력으로 학생들을 모두 배정하기 위해 필요한 최소한의 방의 수를 출력한다.
    """

    N, K = tuple(map(int, input().split()))
    # index : grade
    male_student_list = [0] * 6 
    female_student_list = [0] * 6

    for _ in range(N):
        # 0 : female
        # 1 : male
        gender, grade = tuple(map(int, input().split()))
        if gender: # male
            male_student_list[grade-1]+=1
        else:
            female_student_list[grade-1]+=1

    print(
        func13300(K, male_student_list, female_student_list)
    )