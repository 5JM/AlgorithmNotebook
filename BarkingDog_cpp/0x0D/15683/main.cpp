#include <iostream>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;

int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int,int> > cctv; // cctv의 좌표를 저장할 변수

bool OOB(int a, int b){ // Out Of Bounds 확인
    return a < 0 || a >= n || b < 0 || b >= m;
}

// (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
void process(int x, int y, int dir){
    dir %= 4; // 남 동 북 서

    while(true){
        x += dx[dir];
        y += dy[dir];

        // 범위를 벗어났거나 벽을 만나면 함수를 탈출
        if(OOB(x,y) || board2[x][y] == 6) return; 
        
        // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
        if(board2[x][y] != 0) continue; 
        
        board2[x][y] = 7; // 빈칸을 7로 덮음
    }
}

/*
0: empty
1~5: num of cctv
6: block
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int result = 0; // 사각 지대의 최소 크기 (=답)

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board1[i][j];

            if(board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back(make_pair(i, j));

            if(board1[i][j] == 0) result++;
        }
    }

    // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미.
    // pow함수는 실수형을 인자로 받음.
    // 유효 숫자 범위가 달라 오차가 생길 수 있으니 아래와 같이 사용

    // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각
    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); ++tmp){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];

        int brute = tmp;    

        for(int i = 0; i < cctv.size(); ++i){
            int x = cctv[i].X;
            int y = cctv[i].Y;
            
            int dir = brute % 4;

            if(board1[x][y] == 1){
                process(x,y,dir);
            }
            else if(board1[x][y] == 2){
                process(x,y,dir);
                process(x,y,dir+2);
            }
            else if(board1[x][y] == 3){
                process(x,y,dir);
                process(x,y,dir+1);
            }
            else if(board1[x][y] == 4){
                process(x,y,dir);
                process(x,y,dir+1);
                process(x,y,dir+2);
            }
            else{ // board1[x][y] == 5
                process(x,y,dir);
                process(x,y,dir+1);
                process(x,y,dir+2);
                process(x,y,dir+3);
            }

            brute /= 4;
        }

        int val = 0;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                val += (board2[i][j]==0);

        result = min(result, val);
    }
    cout << result;

    return 0;
}