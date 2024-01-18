#include <iostream>
#include "func.h"

using namespace std;

// 유클리드 호제법
int gcd(int a, int b){
    while (b != 0)
    {
        int r = a % b ;
        a = b;
        b = r;
    }
    
    return b;
}

int main(){
    // 문제1
    // cout<<func1(16)<<endl;
    // cout<<func1(34567)<<endl;
    // cout<<func1(27639)<<endl;

    // 문제2
    // int arr1[] = {1,52,48};
    // int arr2[] = {50,42};
    // int arr3[] = {4, 13, 63, 87};

    // cout<< func2(arr1, 3)<<endl;
    // cout<< func2(arr2, 2)<<endl;
    // cout<< func2(arr3, 4)<<endl;


    // 문제3
    // cout<< func3(9)<<endl;
    // cout<< func3(693953651)<<endl;
    // cout<< func3(756580036)<<endl;

    // 문제4
    cout<< func4(5)<<endl;
    cout<< func4(97615282)<<endl;
    cout<< func4(1024)<<endl;

    return 0;
}