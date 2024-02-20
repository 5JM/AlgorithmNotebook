#include <iostream>
#include <queue>
#include <string>

#define X first
#define Y second

using namespace std;

int board[1002][1002];
// [][][0] 벽을 부수기 전까지의 방문 횟수
// [][][1] 벽을 부순 후(부순 벽에서부터) 방문 횟수
int vis[1002][1002][2]; 
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
            board[i][j] = int(tmp[j] - '0');
        }
    }

     // (x, y), (벽 부순 여부)
    queue<pair<pair<int, int>, bool> > Q;

    Q.push(
        make_pair(
            make_pair(0,0), 0
        )
    );
    vis[0][0][0] = 1;
    vis[0][0][1] = 1;

    while(!Q.empty()){
        pair<int, int> cur = Q.front().X;
        bool isBroken = Q.front().Y;
        Q.pop();
        
        if(cur.X == n-1 && cur.Y == m-1) {
            cout<< vis[cur.X][cur.Y][isBroken];
            return 0;
        }

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >=  n || y < 0 || y >= m) continue;

            /*
                벽을 만나기 전까지 BFS
            */
            // 벽이 아니고
            if(board[x][y] == 0) {
                // 이미 방문했다면
                if(vis[x][y][isBroken]) continue;
                
                // 처음 방문이면
                vis[x][y][isBroken] = vis[cur.X][cur.Y][isBroken] + 1;
                Q.push(
                    make_pair(
                        make_pair(x, y),
                        isBroken
                    )
                );
            }

            /*
                벽을 만났으면, 해당 위치(벽)에서 다시 BFS
            */
            // 벽을 만났고
            // 벽을 부수지 않았으며 처음 방문할때 
            else if(!isBroken && !vis[x][y][isBroken]){
                vis[x][y][1] = vis[cur.X][cur.Y][isBroken] + 1;
                Q.push(
                    make_pair(
                        make_pair(x, y),1
                    )
                );
            }
        }
    }

    cout<< "-1";
    
    return 0;

}
/*
6 5
00000
11110
00000
01111
01111
00010
*/