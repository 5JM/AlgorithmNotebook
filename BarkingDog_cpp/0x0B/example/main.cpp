#include <utility>
#include <iostream>

using namespace std;

// n ~ 1까지 출력(재귀)
void func1(int n){
    if(n == 0) return;

    cout<< n;
    func1(n-1);
}

// 1~n까지의 합 (재귀)
int func2(int n){
    if(n == 0) return 0;
    
    return n + func2(n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    func1(10);
    
    cout<< "\n" << func2(10);

    return 0;
}