#include <iostream>

using namespace std;

int n, s, cnt, arr[21];

void func1182(int cur, int tot){
    if(cur == n){
        if(tot == s) cnt++;
        return ;
    }
    
    func1182(cur+1, tot);

    func1182(cur+1, tot + arr[cur]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    func1182(0, 0);

    if(s == 0) cnt--; // 공집합 제외

    cout << cnt;

    return 0;
}