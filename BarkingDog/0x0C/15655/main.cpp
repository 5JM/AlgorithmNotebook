#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10], num[10];
bool isUsed[100000];

void func15655(int k, int start){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i < n; ++i){
        if(!isUsed[i]){
            arr[k] = num[i];

            for(int j = i; j >= 0; --j)
                isUsed[j] = true;

            func15655(k + 1, i);

            for(int j = i; j >= 0; --j)
                isUsed[j] = false;
        }
    }
}

void func15655UsePermu(){
    int flags[n];

    fill(flags, flags + m, 0);
    fill(flags + m, flags + n, 1);

    do{
        for(int i = 0; i < n; ++i){
            if(!flags[i])
                cout << num[i] << ' ';
        }
        cout<< '\n';

    }while(next_permutation(flags, flags+n));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> num[i];

    sort(num, num + n);

    // back tracking
    // func15655(0, 0);

    // next_permutation
    func15655UsePermu();

    return 0;
}