#include <iostream>
#include <utility>

using namespace std;

int board[130][130];
int blue = 0, white = 0;

void funcT(int n, int r, int c){
    int color = board[r][c];
    int half = n / 2;

    for(int i = r; i < r + n; ++i){
        for(int j = c; j < c + n; ++j){
            if(color != board[i][j]) {
                 // 좌상
                funcT(half, r, c);

                // 우상
                funcT(half, r, c + half);

                // 좌하
                funcT(half, r + half, c);

                // 우하
                funcT(half, r + half, c + half);

                return;
            }
        }
    }
    
    if(color == 0) white++;
    else blue++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> board[i][j];
    }

    funcT(n, 0, 0);

    cout<< white << "\n" << blue;

    return 0;
}