#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func15650(int k){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout<< arr[i] <<' ';
        cout<< '\n';
        return ;
    }

    for(int i = 1; i <= n; ++i){
        if(!isUsed[i]){
            arr[k] = i;

            for(int j = i; j != 0; --j)
                isUsed[j] = true;

            func15650(k+1);

            for(int j = i; j != 0; --j)
                isUsed[j] = false;
        }
    }
}

void func15650UsePermu(){
    int flags[n];

    fill(flags, flags+m, 0);
    fill(flags+m, flags+n, 1);

    do{
        for(int i = 0; i < n; ++i)
            if(!flags[i]){
                cout<< i+1 << ' ';
            }
            cout<< '\n';
    }while(next_permutation(flags, flags+n));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // back tracking
    // func15650(0);

    // next_permutation
    func15650UsePermu();

    return 0;
}