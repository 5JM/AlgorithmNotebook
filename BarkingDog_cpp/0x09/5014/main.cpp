#include <iostream>
#include <queue>

using namespace std;

int vis[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    fill(vis, vis+1000002, -1);

    int dx[2] = {U, D * -1}; 
    // F
    // G
    // S
    queue<int> Q;
    Q.push(S);
    vis[S] = 0;


    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        if(cur == G) {
            cout << vis[cur];
            return 0;
        }

        for(int i = 0; i < 2; ++i){
            int x = cur + dx[i];

            if(x < 1 || x > F) continue;

            if(vis[x] >= 0) continue;

            Q.push(x);
            vis[x] = vis[cur] + 1;
        }
    }

    cout << "use the stairs" ;

    return 0;
}