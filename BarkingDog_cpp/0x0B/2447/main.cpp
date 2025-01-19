#include <iostream>
#include <string>

using namespace std;

string result;

void func2447(int n, int r, int c){
    if((r / n) % 3 == 1 && (c / n) % 3 == 1) result+=" ";
    else if(n / 3 == 0) result+="*";
    else func2447(n/3, r, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            func2447(n, i, j);
        }
        result+="\n";
    }
    
    cout<< result;

    return 0;
}