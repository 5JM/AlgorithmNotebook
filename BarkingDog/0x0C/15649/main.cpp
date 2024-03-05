#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func15649(int k){ // 현재 k개까지 선택
    if(k == m){ // m개를 모두 선택했다면
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' '; // arr에 기록한 수 출력
        cout<<'\n';
        
        return ;
    }

    for(int i = 1; i <= n; ++i){ // 1부터 n까지 수에 대해
        if(!isUsed[i]){ // 아직 i가 사용되지 않았으면
            arr[k] = i; // k번째 수를 i로 정함
            isUsed[i] = true; // i 사용 표시
            
            func15649(k+1); // 다음 수를 정하러 다음 단계로
            
            // k번째 수를 i로 정한 모든 경우에 대해 확인했으니 
            // i를 이제 사용되지 않았다고 명시
            isUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func15649(0);

    return 0;
}