#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

char board[25][25];
int vis[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        fill(board[i], board[i]+25, '0');
        fill(vis[i], vis[i]+25, -1);
    }

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string tmp;
        getline(cin, tmp);

        for(int j = 0; j < n; ++j){
            board[i][j] = tmp[j];
        }
    }

    queue<pair<int, int> > Q;
    vector<int> result;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == '0' || vis[i][j] != -1) continue;
            else{
                Q.push(make_pair(i, j));
                vis[i][j] = 0;
                int cnt = 0;

                while (!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    cnt++;

                    for(int z = 0; z < 4; ++z){
                        int x = cur.X + dx[z];
                        int y = cur.Y + dy[z];

                        if(x < 0 || x >= n || y < 0 || y >= n) continue;
                        if(board[x][y] == '0' || vis[x][y] >= 0 ) continue;

                        Q.push(make_pair(x, y));
                        vis[x][y] = vis[cur.X][cur.Y] + 1;
                    }
                }

                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<"\n";

    for(int i = 0; i < result.size(); ++i){
        cout<<result[i]<<"\n";
    }

    return 0;
}