#include <iostream>
#include "func1.h"

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

    cout<<func1(16)<<endl;
    cout<<func1(34567)<<endl;
    cout<<func1(27639)<<endl;

    return 0;
}