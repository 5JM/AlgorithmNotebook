#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void printArr(int arr[], int& len){
    for(int i = 0; i < len; ++i) cout<< arr[i]<<" ";
    cout<<"\n";
}

/*
백준 2576 홀수 - 브론즈3
문제 .
7개의 자연수가 주어질 때, 이들 중 홀수인 자연수들을 모두 골라 그 합을 구하고, 고른 홀수들 중 최솟값을 찾는 프로그램을 작성하시오.

예를 들어, 7개의 자연수 12, 77, 38, 41, 53, 92, 85가 주어지면 이들 중 홀수는 77, 41, 53, 85이므로 그 합은

77 + 41 + 53 + 85 = 256

이 되고,

41 < 53 < 77 < 85

이므로 홀수들 중 최솟값은 41이 된다.

ex input 1.
12
77
38
41
53
92
85

out 1.
256
41

input 2.
2
4
20
32
6
10
8

out 2.
-1
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[7]; 

    int sum = 0;
    int min = INT_MAX;

    for(int i = 0; i < 7; ++i){
        cin >> arr[i];
    }

    
    for(int i = 0; i < 7; ++i){
        
        if(arr[i]%2 != 0){
            sum += arr[i];

            if(min > arr[i]) min = arr[i];
        }
    }

    if(sum == 0){
        cout<< -1;
    }else{
        cout<<sum<<"\n"<<min;
    }

    return 0;
}