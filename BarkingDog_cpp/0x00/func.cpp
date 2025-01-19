#include "func.h"

using namespace std;

void printArr(int arr[], int& len){
    for(int i = 0; i < len; ++i) cout<< arr[i]<<" ";
    cout<<"\n";
}

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

/*
문제2.주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 
func2(int arr[], int N)을 작성하라. arr의 각 수는 0이상 100이하고 N은 1000이하이다.

O(N)로도 할 수 있다...

input 
1) {1,52,48}, 3 = 1
2) {50,42}, 2 = 0
3) {4, 13, 63, 87}, 4 = 1
*/

// O(N^2) version
int func2(int arr[], int N){
    int result = 0;

    for(int i = 0; i < N - 1; ++i){
        for(int j = i + 1; j < N; ++j){
            if(arr[i] + arr[j] == 100){
                result = 1;
                break;
            }
        }
    }

    return result;
}


// O(N) version
int func2New(int arr[], int N){
    int cntArr[101];
    int len = 101;
    int result = 0;

    fill(cntArr, cntArr+101, 0);

    for(int i = 0; i < N; ++i){
        int tmp = arr[i];
        
        if(cntArr[100 - tmp] > 0){
            return 1;
        }

        cntArr[tmp]++;
    }


    return 0;
}

/*
문제3.N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성하라.
N은 10억 이하의 자연수이다.

input 
1) 9 = 1
2) 693953651= 0
3) 756580036 = 1
*/

int func3(int N){
    for(int i = 0; i < N; ++i){
        if(i*i == N) return 1;
    }
    return 0;
}

/*
문제4.N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라.
N은 10억 이하의 자연수이다.

input 
1) 5 = 4
2) 97615282= 67108864
3) 1024 = 1024
*/
int func4(int N){
    int val = 1;

    while( 2 * val <= N ){
        val *= 2;
    }

    return val;
}