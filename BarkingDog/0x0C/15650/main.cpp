#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func15650(int k){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout<< arr[i] <<' ';
        cout<< '\n';
        return ;
    }

    for(int i = 1; i <= n; ++i){
        if(!isUsed[i]){
            arr[k] = i;

            for(int j = i; j != 0; --j)
                isUsed[j] = true;

            func15650(k+1);

            for(int j = i; j != 0; --j)
                isUsed[j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func15650(0);

    return 0;
}