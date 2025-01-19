#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

bool board[500][500];
bool vis[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cntPic = 0, sizePic = 0;
    

    cin >> m >> n;

    // init board
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int tmp;
            cin >> tmp;

            if(tmp) board[i][j] = 1;
        }
    }
    
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            

            if(board[i][j] == 1 && vis[i][j] == 0){
                int curPicSize = 0;
                queue<pair<int, int> > Q;
                
                vis[i][j] = 1;
                Q.push(make_pair(i, j));
                
                cntPic++;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    curPicSize++;

                    for(int z = 0; z < 4; ++z){
                        int nx = cur.X + dx[z];
                        int ny = cur.Y + dy[z];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                        if(vis[nx][ny] || board[nx][ny] == 0) continue;

                        Q.push(make_pair(nx, ny));

                        vis[nx][ny] = 1;
                    }
                }

                if(sizePic < curPicSize) sizePic = curPicSize;
            }
        }
    }

    cout<< cntPic <<"\n";
    cout<< sizePic;


    return 0;
}