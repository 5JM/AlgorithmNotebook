#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10], num[10];

void func15657(int k, int start){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = start; i < n; ++i){
        arr[k] = num[i];
        
        func15657(k+1, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> num[i];

    sort(num, num + n);

    // k, start
    func15657(0, 0);

    return 0;
}