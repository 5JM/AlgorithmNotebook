#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

int board[102][102];

bool vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int result = 999999999;

void makeLand(int initX, int initY, int landN){
    vis[initX][initY] = true;
    board[initX][initY] = landN;
    queue<pair<int, int> > Q;
    Q.push(make_pair(initX, initY));

    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0|| x >= n || y < 0 || y >= n) continue;

            if(board[x][y] == 0 || vis[x][y]) continue;

            Q.push(make_pair(x, y));
            vis[x][y] = true;
            board[x][y] = landN;
        }
    }
}

void searchBridge(int landNum){
    queue<pair<int, int> > Q;

    for(int i = 0; i < n; ++i){
        fill(vis[i], vis[i] + 102, false);
    }
    
    for(int i = 0;  i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == landNum) Q.push(make_pair(i, j));
        }
    }

    int cnt = 0;

    while(!Q.empty()){
        int t = Q.size();
        for(int i = 0; i < t; ++i){
            pair<int, int> cur = Q.front();
            Q.pop();

            for(int dir = 0; dir < 4; ++dir){
                int x = cur.X + dx[dir];
                int y = cur.Y + dy[dir];

                if(x < 0|| x >= n || y < 0 || y >= n) continue;

                if(board[x][y] == landNum || vis[x][y]) continue;

                // 다른 섬을 만났을 때
                if(board[x][y] != 0){
                    result = min(result, cnt);
                    return ;
                }

                Q.push(make_pair(x, y));
                vis[x][y] = true;
            }
        }

        cnt++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];
        }
    }

    int clusterN = 1;

    // 섬에 번호 매기기
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(vis[i][j]) continue;

            if(board[i][j] != 1) continue;

            makeLand(i, j, clusterN++);
            
        }
    }

    // 섬을 하나씩 확장시키면서 다리 길이 계산
    for(int i = 1; i <= clusterN; ++i)
        searchBridge(i);

    cout<< result;

    return 0;
}