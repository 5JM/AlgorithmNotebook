#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[52][52];
int vis[52][52];

int n,m, baechu;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func2(int _x, int _y, int &cnt){
    queue<pair<int, int> > Q;
    Q.push(make_pair(_x, _y));
    vis[_x][_y] = 1;
    
    cnt++;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= m || y < 0 || y >= n) continue;

            if(board[x][y] == 0 || vis[x][y] > 0) continue;

            Q.push(make_pair(x, y));
            vis[x][y] = 1;
        }
    }
}

int func(int n, int m){
    int cnt = 0;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 1 && vis[i][j] == 0){

                func2(i, j, cnt);
            }
        }
    }

    // reset board & vis
    for(int i = 0; i < 52; ++i){
        fill(board[i], board[i]+52, 0);

        fill(vis[i], vis[i]+52, 0);
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>> t;

    int result[t];

    for(int i = 0; i < t; ++i){
        cin >> m >> n >> baechu;

        for(int j = 0; j < baechu; ++j){
            int x,y;
            cin >> x >> y;

            board[x][y] = 1;
        }

        result[i] = func(n, m);
    }

    for(int i = 0; i < t; ++i){
        cout<<result[i]<<"\n";
    }

    return 0;
}