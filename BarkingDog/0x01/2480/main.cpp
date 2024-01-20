#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, max;

    cin >> a >> b >> c;

    if(a == b && a==c) cout<< 10000 + a * 1000;
    else{
        if(a == b || a == c ) cout<< 1000 + a * 100;
        else if(b == c) cout<< 1000 + b * 100;
        else {
            if(a > b){
                if(a > c) max = a;
                else max = c;
            }
            else{
                if(b > c) max = b;
                else max = c;
            }

            cout<< max * 100;
        }
    }

    return 0;
}