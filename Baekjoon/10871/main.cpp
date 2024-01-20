#include <iostream>

using namespace std;

void func(int x, int n, int a[]){
    
    string result;

    for(int i = 0; i < n; ++i){
        if(a[i] < x) result += to_string(a[i]) + " ";
    }
    
    result.pop_back();

    cout<< result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; 

    cin>> n >> x;

    int a[n];

    for(int i = 0; i < n; ++i){
        cin>> a[i];
    }
    
    func(x, n, a);

    return 0;
}