#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

string toString(int x){
    string tmp = "Escaped in ";
    tmp += to_string(x);
    return tmp + " minute(s).\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string result;

    while(1){
        // L : 빌딩 층 수(z), R : 각 층의 행(x), C : 각 측의 열 (y)
        int l, r, c;
        cin >> l >> r >> c;
        
        if(!l && !r && !c) break;
        
        cin.ignore();

        char board[32][32][32];
        int vis[32][32][32];
        bool isValid = false;

        queue<tuple<int, int, int>> Q;

        // init
        for(int z = 0; z < l; ++z){
            for(int i = 0; i < r; ++i){
                fill(vis[z][i], vis[z][i]+32, -1);
            }
        }
        
        for(int z = 0; z < l; ++z){
            for(int i = 0; i < r+1; ++i){
                string tmp;
                getline(cin, tmp);
                
                if(tmp.size()>0){
                    for(int j = 0; j < c; ++j){
                        if(tmp[j] == 'S'){
                            Q.push(make_tuple(z, i, j));
                            vis[z][i][j] = 0;
                        }
                        board[z][i][j] = tmp[j];
                    }
                }
            }
        }

        while(!Q.empty()){
            tuple<int, int, int> cur = Q.front();
            Q.pop();

            if(board[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 'E'){
                result += toString(vis[get<0>(cur)][get<1>(cur)][get<2>(cur)]);

                isValid = true;
                
                break;
            }

            for(int i = 0; i < 6; ++i){
                int x = get<1>(cur) + dx[i];
                int y = get<2>(cur) + dy[i];
                int z = get<0>(cur) + dz[i];

                if(x < 0 || x >= r || y < 0 || y >= c || z < 0 || z >= l) continue;
                if(board[z][x][y] == '#' || vis[z][x][y] >= 0 ) continue;

                Q.push(make_tuple(z, x, y));
                vis[z][x][y] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
        }

        if(!isValid) {
            result+="Trapped!\n";
        }
    }
    
    cout<<result;

    return 0;
}