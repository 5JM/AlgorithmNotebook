#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

char board[1002][1002];
int vis[1002][1002];
int visFire[1002][1002];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int w, h, initX, initY, fireX, fireY;

void initVis(){
    for(int i = 0; i < h; ++i){
        fill(vis[i], vis[i] + w, -1);
        fill(visFire[i], visFire[i] + w, -1);
    }
}

int func(queue<pair<int, int> > &Q, queue<pair<int, int> > &QFire){

    // fire
    while(!QFire.empty()){
        pair<int, int> cur = QFire.front();
        QFire.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0|| x >= h || y < 0 || y >= w) continue;

            if(board[x][y] == '#' || visFire[x][y] >= 0) continue;
            
            QFire.push(make_pair(x, y));
            visFire[x][y] = visFire[cur.X][cur.Y] + 1;
        }
    }

    // 상근
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0|| x >= h || y < 0 || y >= w){
                return vis[cur.X][cur.Y] + 1;
            }

            if(board[x][y] == '#' || vis[x][y] >= 0) continue;

            if(visFire[x][y] != -1 && (vis[cur.X][cur.Y]+1 >= visFire[x][y])) continue;

            Q.push(make_pair(x, y));
            vis[x][y] = vis[cur.X][cur.Y] + 1;
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    int results[t];

    for(int i = 0; i < t; ++i){

        queue<pair<int, int> > QFire, Q;

        cin >> w >> h;

        initVis();

        cin.ignore();

        for(int x = 0; x < h; ++x){
            string tmp;
            getline(cin, tmp);

            for(int y = 0; y < w; ++y){
                board[x][y] = tmp[y];

                if(tmp[y] == '@'){
                    Q.push(make_pair(x, y));
                    vis[x][y] = 0;
                }
                if(tmp[y] == '*'){
                    QFire.push(make_pair(x, y));
                    visFire[x][y] = 0;
                }
            }
        }

        results[i] = func(Q, QFire);
    }

    for(int i = 0; i < t; ++i){
        if(results[i] == -1){
            cout<< "IMPOSSIBLE\n";
        }else{
            cout<< results[i] << "\n";
        }
        
    }
    return 0;
}