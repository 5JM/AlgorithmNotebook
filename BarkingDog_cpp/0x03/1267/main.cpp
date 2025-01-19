#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 영식 (Y) 30초 : 10원
    // 민식 (M) 60초 : 15원

    int N;

    cin >> N;

    int tmp, Y = 0, M = 0;

    for(int i = 0; i < N; ++i) {
        cin >> tmp;
        Y += (tmp / 30 + 1) * 10;
        M += (tmp / 60 + 1) * 15;
    }

    if(Y == M) cout<< "Y M " << Y;
    else if(Y < M) cout<< "Y " << Y;
    else cout<< "M " << M;
    
    return 0;
}