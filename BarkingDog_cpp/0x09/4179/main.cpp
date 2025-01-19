#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

char board[1001][1001];
int vis[1001][1001];
int fireVis[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    cin.ignore();

    queue<pair<int, int> > Q, Q2;

    for(int i = 0; i < R; ++i){
        string tmp;
        getline(cin, tmp);

        fill(vis[i], vis[i] + 1001, -1);
        fill(fireVis[i], fireVis[i] + 1001, -1);

        for(int j = 0; j < C; ++j){
            board[i][j] = tmp[j];

            if(tmp[j] == 'J'){
                Q2.push(make_pair(i,j));
                vis[i][j] = 0;
            }

            if(tmp[j] == 'F'){
                Q.push(make_pair(i,j));
                fireVis[i][j] = 0;
            }
        }
    }

    // fire root
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= R || y < 0 || y >= C) continue;

            if(board[x][y] == '#' || fireVis[x][y] >= 0) continue;

            Q.push(make_pair(x, y));
            fireVis[x][y] = fireVis[cur.X][cur.Y] + 1;
        }
    }

    // jihoon root
    while(!Q2.empty()){
        pair<int, int> cur = Q2.front();
        Q2.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= R || y < 0 || y >= C) { // 범위를 벗어난 것== 탈출
                cout<< vis[cur.X][cur.Y] + 1;
                return 0;
            }

            if(board[x][y] ==  '#' || vis[x][y] >= 0) continue;

            if(fireVis[x][y] != -1 && (vis[cur.X][cur.Y]+1 >= fireVis[x][y])) continue;

            Q2.push(make_pair(x, y));
            vis[x][y] = vis[cur.X][cur.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}