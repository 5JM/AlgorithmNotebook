#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

int board[100][100];
int vis[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 100; ++i){
        fill(board[i], board[i]+100, -1);
        fill(vis[i], vis[i]+100, -1);
    }
        

    int m, n, k;

    // m : height
    // n : width
    cin >> m >> n >>k;

    for(int i = 0; i < k; ++i){
        int box[4];
        cin >> box[0] >> box[1] >> box[2] >> box[3];

        for(int x = box[0]; x < box[2]; ++x){
            for(int y = box[1]; y < box[3]; ++y){
                board[y][x] = 0;
            }
        }
    }

    queue<pair<int, int> > Q;
    vector<int> result;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] != -1 || vis[i][j] >= 0 ) continue;
            else{
                Q.push(make_pair(i,j));
                vis[i][j] = 0;
                int last = 0;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    last++;

                    for(int z = 0; z < 4; ++z){
                        int x = dx[z] + cur.X;
                        int y = dy[z] + cur.Y;

                        if(x < 0 || x >= m || y < 0 || y >= n) continue;

                        if(board[x][y] == 0 || vis[x][y] >= 0) continue;

                        Q.push(make_pair(x, y));
                        vis[x][y] = vis[cur.X][cur.Y]+1;
                    }
                }
                result.push_back(last);
            }
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<"\n";
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i]<<" ";

    return 0;
}