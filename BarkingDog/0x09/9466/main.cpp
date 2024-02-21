#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[100002];
bool vis[100002];
bool done[100002];

int result = 0;

void reset(){
    fill(board, board+100002, 0);
    fill(vis, vis+100002, false);
    fill(done, done+100002, false);

    result = 0;
}

void func(int node){
    vis[node] = true;

    int nxt = board[node];

    if(!vis[nxt]) func(nxt);
    // 재방문은 했지만 아직 사이클이 아니라면 nxt까지 포함해서 사이클 완성
    else if(!done[nxt]){
        // 사이클을 카운트
        for(int i = nxt; i != node; i = board[i]){
            result++;
        }
        // 자기 자신 카운트
        result++;
    }
    
    done[node]= true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;

        for(int j = 1; j <= n; ++j) cin >> board[j];
        

        for(int j = 1; j <= n; ++j){
            // 방문하지 않은 곳만
            if(!vis[j]) func(j);
        }
        
        cout<< n - result << "\n";
        
        reset();
    }


    return 0;
}