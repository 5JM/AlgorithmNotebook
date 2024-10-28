// #include <bits/stdc++.h>
#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std;

int n, m, k;
int board[52][15];

vector<pair<int, int> > chickens, houses;

int chickenDistance(vector<int> brute){ // 조합을 입력으로
    int tmp = 0x7f7f7f7f;
    int dist = 0;

    for(vector<pair<int, int> >::iterator h = houses.begin(); h != houses.end(); ++h){
        for(int i = 0; i < chickens.size(); ++i){
            if(brute[i] == 0) continue;

            tmp = min(tmp, abs((*h).X - chickens[i].X) + abs((*h).Y - chickens[i].Y));
        }
        dist += tmp;
    }

    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];

            if(board[i][j] == 2) {
                chickens.push_back(make_pair(i, j));
            }

            if(board[i][j] == 1) {
                houses.push_back(make_pair(i, j));
            }
        }
            
    
    vector<int> tmp(chickens.size());

    for(int i = 0; i < m; ++i) tmp[i] = 1;
    
    

    // 전체 치킨집 중에 m개만 고르기 : 조합
    do{
        for(int i = 0; i < chickens.size(); ++i){
            if(tmp[i] == 0) continue;

            pair<int, int> val = chickens[i];
            cout<< val.first << ", "<<val.second<<'\n';
        }
    }while(next_permutation(tmp.begin(), tmp.end()));

    return 0;
}

/*
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2
*/