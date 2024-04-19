// #include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[21][21];
int board2[21][21];

void rotate(){
    // clock-wise 90
    int tmp[21][21];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            tmp[i][j] = board2[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            board2[i][j] = tmp[n-j-1][i];
        }
    }
}

/*
    i = 0, idx = 0; continue

    i = 1, idx = 0; 
    tilted[0] == 0 -> tilted[0] = 2  ; {2,0,0,0,0,0,0,0,0}

    i = 2, idx = 0; continue

    i = 3, idx = 0;
    {tilted[0] = 2} == {arr[3] == 2}; {4,0,}; idx++;

    i = 4, idx = 1;
    tilted[1] == 0 -> tilted[1] = 8; {4, 8, 0,};

    i = 5, idx = 1;
    {tilted[1] = 8} == {arr[5] == 8}; {4,16,0}; idx++;

    i = 6, idx = 2; continue;

    i = 7, idx = 2;
    tilted[2] == 0 -> tilted[2] = 16; {4, 16, 16, 0};

*/

void tilt(int dir){
    while(dir--){
        rotate();
    }

    for(int i = 0; i < n; ++i){
        int tilted[21] = {};
        int idx = 0;

        for(int j = 0; j < n; ++j){
            if(board2[i][j] == 0) continue;

            if(tilted[idx] == 0) tilted[idx] = board2[i][j];

            else if(tilted[idx] == board2[i][j]) tilted[idx++] *= 2;
            
            else tilted[++idx] = board2[i][j];
        }

        for(int j = 0; j < n; ++j) board2[i][j] = tilted[j];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];
        }
    }

    int result = 0;

    // 4^5 : 4방향에 대해서 5번 기울이기
    for(int tmp = 0; tmp < 1024; ++tmp){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                board2[i][j] = board[i][j];
            }
        }

        int brute = tmp;

        for(int i = 0; i < 5; ++i){
            int dir = brute % 4;
            brute /= 4;

            tilt(dir);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                result = max(result, board2[i][j]);
            }
        }
    }

    cout << result;

    return 0;
}
/*
    2 2 2
    4 4 4
    8 8 8

    4 2 0
    8 4 0
    16 8 0

    0 4 2 
    0 8 4 
    0 16 8 

8
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
0 2 0 2 8 8 0 16
*/