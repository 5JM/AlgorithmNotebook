#include <iostream>
#include <algorithm>

using namespace std;

/*
백준 10093 숫자 - 브론즈2
*/

void swap(unsigned long long &a, unsigned long long &b){
    uint64_t tmp = a;
    a = b;
    b = tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long a, b;

    cin >> a >> b;

    if(a == b) {
        cout<< 0;
        return 0;
    }

    if(a > b) swap(a, b);

    cout<< b - a - 1<<"\n";

    for(unsigned long long i = a + 1; i < b; ++i)
        cout<< i << " ";


    return 0;
}