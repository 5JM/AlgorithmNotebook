#include <iostream>

using namespace std;

int board[2200][2200];
int mOne, zero, one;

void func1780(int n, int r, int c){
    int cur = board[r][c];
    int oneThird = n/3, twoThird = 2 * n/3;

    for(int i = r; i < r + n; ++i){
        for(int j = c; j < c + n; ++j){
            if(cur != board[i][j]){
                
                func1780(oneThird, r, c);

                func1780(oneThird, r, c+oneThird);

                func1780(oneThird, r, c+twoThird);

                func1780(oneThird, r+oneThird, c);

                func1780(oneThird, r+twoThird, c);

                func1780(oneThird, r+oneThird, c+oneThird);

                func1780(oneThird, r+oneThird, c+twoThird);

                func1780(oneThird, r+twoThird, c+oneThird);

                func1780(oneThird, r+twoThird, c+twoThird);

                return ;
            }
        }
    }

    if(cur==-1) mOne++;
    else if(cur == 0) zero++;
    else one++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n ;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> board[i][j];
    }

    func1780(n, 0, 0);

    cout << mOne << "\n" << zero << "\n" << one;

    return 0;
}