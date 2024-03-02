#include <iostream>
#include <string>

using namespace std;

char board[64][64];
string result;

void func1992(int n, int r, int c){
    char cur = board[r][c];
    int half = n/2;

    for(int i = r; i < r + n; ++i){
        for(int j = c; j < c + n; ++j){
            if(cur != board[i][j]){
                result+="(";
                
                func1992(half, r, c);

                func1992(half, r, c+half);

                func1992(half, r+half, c);

                func1992(half, r+half, c+half);
                
                result+=")";
                return ;
            }
        }
    }

    
    result+=cur;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string tmp;
    
        getline(cin, tmp);

        for(int j = 0; j < n; ++j)
            board[i][j] = tmp[j];
    }

    func1992(n, 0, 0);

    cout<<result;

    return 0;
}