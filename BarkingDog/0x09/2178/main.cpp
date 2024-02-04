#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

char board[101][101];
int vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string tmp;
        getline(cin, tmp);

        for(int j = 0; j < m; ++j){
            board[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < n; ++i)
        fill(vis[i], vis[i]+m, -1);

    queue<pair<int, int> > Q;
    Q.push(make_pair(0,0));
    vis[0][0] = 0;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;

            if(board[nx][ny] != '1' || vis[nx][ny] >= 0) continue;

            Q.push(make_pair(nx, ny));
            vis[nx][ny] = vis[cur.X][cur.Y]+1;
        }
    }

    cout<< vis[n-1][m-1]+1;

    return 0;
}