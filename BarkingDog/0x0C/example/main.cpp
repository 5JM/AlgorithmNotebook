#include <iostream>

using namespace std;

/*
    9663 - N - Queen
*/

int n, cnt, board[14][14];

// 열, /, \

bool isUsedCol[30], isUesdCross1[30], isUesdCross2[30];

void func9663(int cur){
    if(cur == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n; ++i){
        if(isUsedCol[i] || isUesdCross1[cur+i] || isUesdCross2[cur - i + n - 1])
            continue;
            
        isUsedCol[i] = true;
        isUesdCross1[cur+i] = true;
        isUesdCross2[cur-i+n-1] = true;

        func9663(cur+1);

        isUsedCol[i] = false;
        isUesdCross1[cur+i] = false;
        isUesdCross2[cur-i+n-1] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    func9663(0);

    cout << cnt;

    return 0;
}