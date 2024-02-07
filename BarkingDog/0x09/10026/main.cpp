#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

char board[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func2(int n, int initX, int initY, int &cnt){
    queue<pair<int, int> > Q;
    
    Q.push(make_pair(initX,initY));

    vis[initX][initY] = 1;
    
    cnt++;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();


        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= n) continue;

            if(board[cur.X][cur.Y] != board[x][y] ||  vis[x][y] > 0) continue;
            
            Q.push(make_pair(x, y));
            vis[x][y] = 1;
        }
    }
}

int func(int n){
    int result = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!vis[i][j]){
                func2(n, i, j, result);
            }
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, results[2];
    cin >> n;

    cin.ignore();

    // init board
    for(int i = 0; i < n; ++i){
        string tmp;
        getline(cin, tmp);

        for(int j = 0; j < n; ++j){
            board[i][j] = tmp[j];
        }
    }
    
    
    // 일반
    results[0] = func(n);

    //reset
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 'R') board[i][j] = 'G';
            
            vis[i][j] = 0;
        }
    }
    
    // 적록색약
    results[1] = func(n);
    
    cout<< results[0] << " " << results[1];

    return 0;
}