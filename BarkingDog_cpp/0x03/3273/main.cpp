#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, v, result = 0;
    int cnt[2000001];

    fill(cnt, cnt + 2000001, 0);

    cin >> N;

    int inputs[N];

    for(int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;

        cnt[tmp] = 1;
        inputs[i] = tmp;
    }

    cin >> v;

    for(int i = 0; i < N; ++i){
        int tmp = v - inputs[i];
        /*
            1. index오류 방지
            2. 합이 v인 원소가 배열에 있는지 확인
            3. a_j가 a_i 를 만족하는지 확인
        */
        if(tmp >= 0 && cnt[tmp] == 1 && tmp > inputs[i]) {
            result++;

            cnt[inputs[i]] = 0;
        }
    }

    cout<< result;

    return 0;
}