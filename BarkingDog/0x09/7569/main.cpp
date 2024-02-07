#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

#define X first
#define Y second

using namespace std;

int board[102][102][102];
int vis[102][102][102];

int n,m,h;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;

    queue<tuple<int, int, int> > Q;

    for(int z = 0; z < h; ++z){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int tmp;
                cin >> tmp;

                board[z][i][j] = tmp;

                if(tmp == 1){
                    Q.push(make_tuple(z, i, j));
                }else if(tmp == 0){
                    vis[z][i][j] = -1;
                }
            }
        }            
    }
    
    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 6; ++i){
            int x = get<1>(cur) + dx[i];
            int y = get<2>(cur) + dy[i];
            int z = get<0>(cur) + dz[i];

            if(x < 0 || x >=n || y < 0 || y >= m || z < 0 || z >= h) continue;

            if(board[z][x][y] == -1 || vis[z][x][y] >= 0) continue;

            Q.push(make_tuple(z, x, y));
            vis[z][x][y] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
        }
    }

    int cnt = 0;

    for(int z = 0; z < h; ++z){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(vis[z][i][j] == -1){
                    cout<< -1;
                    return 0;
                }

                cnt = max(cnt, vis[z][i][j]);
            }
        }            
    }

    cout<< cnt;

    return 0;
}