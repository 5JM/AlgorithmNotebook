#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int board[302][302];
int vis[302][302];

int dx[8] = {2, 2, -1, 1, -2, -2, -1, 1};
int dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};

int l;

int func(pair<int, int> init, pair<int, int> target){
    queue<pair<int, int> > Q;
    bool breakTrigger = 0;

    Q.push(init);
    vis[init.X][init.Y] = 1;

    int cnt = 0;

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 8; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= l || y < 0 || y >= l) continue;

            if(cur.X == target.X && cur.Y == target.Y){
                breakTrigger = 1;
                cnt = vis[cur.X][cur.Y] - 1;
                break;
            }

            if(board[x][y] != 0 || vis[x][y] != -1) continue;

            Q.push(make_pair(x,y));
            vis[x][y] = vis[cur.X][cur.Y] + 1;
        }

        if(breakTrigger) break;
    }
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int results[t];

    for(int i = 0; i < 302; ++i)
        fill(vis[i], vis[i]+302, -1);

    for(int i = 0; i < t; ++i){
        int x, y, targetX, targetY;

        cin  >> l;

        cin >> x >> y;

        cin >> targetX >> targetY;

        results[i] = func(make_pair(x, y), make_pair(targetX, targetY));

        for(int i = 0; i < 302; ++i)
            fill(vis[i], vis[i]+302, -1);
    }

    for(int i = 0; i < t; ++i)
        cout<< results[i]<<"\n";

    return 0;
}