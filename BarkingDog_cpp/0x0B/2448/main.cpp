#include <iostream>

using namespace std;

char board[3072][6144];
int dx[8] = {0, 1, 1, 2, 2, 2, 2, 2};
int dy[8] = {0, -1, 1, -2, -1, 0, 1, 2};

void func2448(int n, int r, int c){
    // base triangle
    if( n == 3 ){
        for(int i = 0; i < 8; ++i){
            int x = r + dx[i];
            int y = c + dy[i];
            
            board[x][y]= '*';
        }
        
    }
    else{
        int half = n / 2;
        // top
        func2448(half, r, c);
        // left
        func2448(half, r + n / 2, c - n / 2);
        // right
        func2448(half, r + n / 2, c + n / 2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i <3072; ++i)
        fill(board[i], board[i]+6144, ' ');

    // top vertex (0, n-1)
    func2448(n, 0, n-1);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2*n-1; ++j){
            cout<< board[i][j];
        }
        cout<<"\n";
    }

    return 0;
}