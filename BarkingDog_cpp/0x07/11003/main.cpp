#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    string result;
    deque<pair<int, int> > dq;

    cin >> N >> L;

    int min;

    for(int i = 1; i <= N; ++i){
        int tmp;
        cin >> tmp;

        // main 조건) front에 가장 작은 수가 있어야 참조할 때 O(n)=1
        if(!dq.empty()){
            if(dq.front().first == i - L) // idx 조건
                dq.pop_front();
            while( !dq.empty() && dq.back().second > tmp ){ 
                // 다음에 들어올 수가 deque에 들어있는 back 보다 작으면 
                // 해당 back은 앞으로 최소 값이 될 수 없기때문에 
                // 새로 들어오는 수보다 작은 수들은 전부 pop
                dq.pop_back();
            }
        }

        dq.push_back(make_pair(i,tmp));
        
        result += to_string(dq.front().second);
        result += " ";
    }

    cout<<result;

    return 0;
}