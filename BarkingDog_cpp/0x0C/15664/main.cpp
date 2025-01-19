#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[10], num[10];
bool isUsed[10];

void func15664(int k){
    if(k == m){
        for(int i = 0; i < m; ++i){
            cout<< arr[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    int tmp = 0;
    for(int i = 0; i < n; ++i){
        if(!isUsed[i] && num[i] != tmp){
            arr[k] = num[i];
            tmp = num[i];

            for(int j = i; j >= 0; --j)
                isUsed[j] = true;

            func15664(k + 1);

            for(int j = i; j >= 0; --j)
                isUsed[j] = false;
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

    func15664(0);

    return 0;
}