#include <iostream>
#include <deque>
#include <queue>

using namespace std;

void func1(deque<int> &dq){
    if(!dq.empty()){
        dq.pop_front();
    }
}

void func2(deque<int> &dq, int  &cnt){
    if(!dq.empty()){
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);

        cnt++;
    }
}

void func3(deque<int> &dq, int  &cnt){
    if(!dq.empty()){
        int tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);
        cnt++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, cnt = 0;
    cin >> N >> M;

    deque<int> dq;
    queue<int> q;

    for(int i = 1; i <= N; ++i){
        dq.push_back(i);
    }

    for(int i = 0; i< M; ++i){
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    while(!q.empty()){

        int tmp = q.front();
        int tmpCnt2 = 0, tmpCnt3= 0;
        deque<int> tmpDq2(dq), tmpDq3(dq);

        while(tmpDq2.front() != tmp){
            func2(tmpDq2, tmpCnt2);
        }

        while(tmpDq3.front() != tmp){
            func3(tmpDq3, tmpCnt3);
        }

        if(tmpCnt2 <= tmpCnt3){
            cnt+=tmpCnt2;

            dq = tmpDq2;
        }else{
            cnt+=tmpCnt3;

            dq = tmpDq3;
        }

        func1(dq);
        q.pop();
    }

    cout << cnt;

    return 0;
}