#include "func1.h"

/*
문제1. N이하의 자연수 중, 3의 배수와 5의 배수인 수를 모두 합한 값을 반환하는
func1(int N)을 작성하라. N은 5만 이하의 자연수.

O(1)로도 할 수 있다...

input 
1) 16 = 60
2) 34567 = 278812814
3) 27639 = 178254968
*/

int func1(int N){
    int sum = 0;
    for(int i = 0; i < N; ++i){
        if(i%3 ==0|| i % 5 == 0)
            sum+=i;
    }

    return sum;
}