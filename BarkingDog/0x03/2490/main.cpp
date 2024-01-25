#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int arr[], int& len){
    for(int i = 0; i < len; ++i) cout<< arr[i]<<" ";
    cout<<"\n";
}

// 백준 2490 윷놀이 - 브론즈 3

/*
문제 .
우리나라 고유의 윷놀이는 네 개의 윷짝을 던져서 배(0)와 등(1)이 나오는 숫자를 세어 도, 개, 걸, 윷, 모를 결정한다. 
네 개 윷짝을 던져서 나온 각 윷짝의 배 혹은 등 정보가 주어질 때 
도(배 한 개, 등 세 개), 개(배 두 개, 등 두 개), 걸(배 세 개, 등 한 개), 윷(배 네 개), 모(등 네 개) 중
어떤 것인지를 결정하는 프로그램을 작성하라.

ex input 1 .
0 1 0 1
1 1 1 0
0 0 1 1

out 1 .
B
A
B
*/

string func(int arr[], int len){
    int result = 0;
    for(int i = 0; i < len; ++i){
        result += arr[i];
    }

    if(result == 0){
        return "D";
    }else if(result == 1){
        return "C";
    }else if(result == 2){
        return "B";
    }else if(result == 3){
        return "A";
    }else {
        return "E";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[4];
    int b[4];
    int c[4];

    cin>> a[0] >> a[1] >> a[2] >> a[3];
    cin>> b[0] >> b[1] >> b[2] >> b[3];
    cin>> c[0] >> c[1] >> c[2] >> c[3];

    cout<<func(a, 4)<<"\n";
    cout<<func(b, 4)<<"\n";
    cout<<func(c, 4)<<"\n";

    return 0;
}