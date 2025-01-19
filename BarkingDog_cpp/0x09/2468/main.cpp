#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, max_h = 0;

int func(int height){
    int _board[102][102];
    int vis[102][102];
    int result = 0;

    for(int i = 0; i < 102; ++i){
        fill(_board[i], _board[i]+102, 0);
        fill(vis[i], vis[i]+102, 0);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] > height) _board[i][j] = 1;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(_board[i][j] != 0 && !vis[i][j]){

                queue<pair<int, int> > Q;
                Q.push(make_pair(i, j));
                vis[i][j] = 1;
                result++;

                while(!Q.empty()){
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for(int z = 0; z < 4; ++z){
                        int x = cur.X + dx[z];
                        int y = cur.Y + dy[z];

                        if(x < 0 || x >= n || y < 0 || y >= n ) continue;
                        if(_board[x][y] == 0 || vis[x][y] == 1) continue;

                        Q.push(make_pair(x, y));
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec;

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int tmp;
            cin >> tmp;

            board[i][j] = tmp;
            if(tmp > max_h) max_h = tmp;
        }
    }

    // 물은 없을 수 도 있어서 1이 아닌 0부터 시작해야함...
    for(int i = 0; i <= max_h; ++i){
        int tmp = func(i);
        vec.push_back(tmp);
    }

    cout << *max_element(vec.begin(), vec.end());

    return 0;
}