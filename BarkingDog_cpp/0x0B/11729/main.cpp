#include <iostream>
#include <math.h>

using namespace std;

// n개의 원판을 기둥 a에서 기둥 b으로 옮기는 방법을 출력
void hanoi(int a, int b, int n){
    if(n==1) { 
        cout<< a << " " << b << "\n";
        return ;
    }

    hanoi(a, 6 - a - b, n-1);

    cout<< a << " " << b << "\n";

    hanoi(6 - a - b, b, n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;

    // 2^a -1
    cout<< (1<<a) - 1 <<"\n";

    hanoi(1, 3, a);

    return 0;
}