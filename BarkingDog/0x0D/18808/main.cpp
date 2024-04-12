// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>

#define X first
#define Y second

using namespace std;

int n, m, num;
int r, c; // sticker

int board[40][40];
int sticker[10][10];

int countBoard(){
    int cnt = 0;

    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == 1) cnt++;
        }
    }

    return cnt;
}

bool canPost(int x, int y){

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c ; ++j){
            if(sticker[i][j] == 1 && board[x + i][y + j] == 1)
                return false;
        }
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c ; ++j){
            if(sticker[i][j] == 1)
                board[x + i][y + j] = 1;
        }
    }
    return true;
}

/*
    (2, 3)
    1 0 1
    1 1 1

    (3, 2)
    1 1
    1 0
    1 1

    i, j   r-j-1, i 
    0, 0 ->  1, 0
    1, 0 ->  1, 1
    2, 0 ->  1, 2

    0, 1 -> 0, 0
    1, 1 -> 0, 1
    2, 1 -> 0, 2
*/

void rotateSticker(){
    // clock-wise 90
    int tmp[10][10];

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            tmp[i][j] = sticker[i][j];
        }
    }

    for(int i = 0; i < c; ++i){
        for(int j = 0; j < r; ++j){
            sticker[i][j] = tmp[r-j-1][i];
        }
    }

    swap(r, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> num;

    for(int s = 0; s < num; ++s){
        cin >> r >> c;

        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cin >> sticker[i][j];
            }
        }

        bool escape = false;

        for(int rotates = 0; rotates < 4; ++rotates){
            if(escape) break;

            for(int i = 0; i < n - r + 1; ++i){
                if(escape) break;

                for(int j = 0; j < m - c + 1; ++j){

                    if(canPost(i, j)){
                        escape = true;
                        break;
                    }
                }
            }

            rotateSticker();
        }
    }
    
    cout<< countBoard();

    return 0;
}