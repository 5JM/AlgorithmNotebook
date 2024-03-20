#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[10], num[10];

void func15666(int k, int start){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }

    int tmp = 0;
    for(int i = start; i < n; ++i){
        if(tmp != num[i]){
            arr[k] = num[i];

            tmp = num[i];

            func15666(k+1, i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> num[i];

    sort(num, num+n);

    func15666(0, 0);

    return 0;
}