#include <iostream>

using namespace std;

int n, m;
int arr[10];

void func15651(int k){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }

    for(int i = 1; i <= n; ++i){
        arr[k] = i;

        func15651(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func15651(0);

    return 0;
}