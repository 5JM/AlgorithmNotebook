#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[1002][1002];
int vis[1002][1002];

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int, int> > Q;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];

            if(board[i][j]==1) Q.push(make_pair(i, j));

            if(board[i][j]==0) vis[i][j] = -1;
        }
    }

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(board[x][y] == -1 || vis[x][y] >= 0) continue;

            Q.push(make_pair(x, y));
            vis[x][y] = vis[cur.X][cur.Y] + 1;
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            // 익지 않은 토마토 중, 처리되지 않은 토마토가 있을 시
            // 32번째 줄 참고
            if(vis[i][j]==-1){ 
                cout<< -1;
                return 0;
            } 
            cnt = max(cnt, vis[i][j]);
        }
    }
    
    cout<< cnt;

    return 0;
}