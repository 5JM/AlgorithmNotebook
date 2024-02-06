#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[100002];

int dx[3] = {1, -1, 2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(board, board+100002, -1);

    queue<int > Q;

    Q.push(n);
    board[n] = 0;

    while(board[k] == -1){
        int cur = Q.front();
        Q.pop();

        for(int i = 0; i < 3; ++i){
            int x;
            if(i != 2) x = cur + dx[i];
            else x = cur * dx[i];
            
            if(x < 0 || x > 100000) continue;

            if(board[x] != -1) continue;

            Q.push(x);
            board[x] = board[cur] + 1;
        }
    }

    cout<< board[k];

    return 0;
}