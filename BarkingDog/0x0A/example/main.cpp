#include <utility>
#include <iostream>
#include <stack>

#define X first
#define Y second

using namespace std;

int board[502][502];
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n = 7, m = 10; 

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > S;
    vis[0][0] = true;
    S.push(make_pair(0, 0));

    whlie(!S.empty()){
        pair<int, int> cur = S.top();
        S.pop();

        for(int i = 0; i < 4; ++i){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 0 || x >= n || y < 0 || y >= m) continue;

            if(board[x][y] != 1 || vis[x][y]) continue;

            S.push(make_pair(x, y));
            vis[x][y] = true;
        }
    }

    return 0;
}