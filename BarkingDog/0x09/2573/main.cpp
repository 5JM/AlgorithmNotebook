#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int board[2][302][302];
bool vis[302][302];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

void reset(){
    for(int i = 0; i < 302; ++i){
        fill(board[1][i], board[1][i]+302, 0);

        fill(vis[i], vis[i]+302, false);
    }
}

void bfs(int initX, int initY){
    queue<pair<int, int> > Q;
    
    Q.push(make_pair(initX, initY));
    vis[initX][initY] = true;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m) continue;

            if(board[0][x][y] && !vis[x][y]){
                Q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }
    }
}

int meltN(int initX, int initY){
    int cnt = 0;

    for(int i = 0; i < 4; ++i){
        int x = initX + dx[i];
        int y = initY + dy[i];

        if(board[0][x][y] == 0) cnt++;
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int tmp;
            cin >> tmp;

            board[0][i][j] = tmp;
        }
    }

    int year = 0;
    
    while(1){
        int cntIceBerg = 0;

        reset();
        
        // 빙산 갯수 구기기
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[0][i][j] && !vis[i][j]){
                    cntIceBerg++;
                    
                    bfs(i, j);
                }
            }
        }

        if(cntIceBerg >= 2){
            cout<< year;
            break;
        }

        // 다 녹아버렸다면
        if(cntIceBerg == 0){
            cout<< 0;
            break;
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[0][i][j]){
                    // 빙산 칸이 얼마나 녹아야하는지 계산
                    board[1][i][j] = board[0][i][j] - meltN(i, j);
                    if(board[1][i][j] < 0) board[1][i][j] = 0;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                board[0][i][j] = board[1][i][j];
            }
        }

        year++;
    }


    return 0;
}