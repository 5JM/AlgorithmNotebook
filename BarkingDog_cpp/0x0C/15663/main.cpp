#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10], num[10];
bool isUsed[10];

void func15663(int k){
    if(m == k){
        for(int i = 0; i < m; ++i){
            cout << arr[i]<< ' ';
        }
        cout<< '\n';
        return;
    }

    int tmp = 0;
    for(int i = 0; i < n; ++i){
        if(!isUsed[i] && tmp != num[i]){
            arr[k] = num[i];

            tmp = num[i];
            isUsed[i] = true;

            func15663(k+1);

            isUsed[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> num[i];
        
    sort(num, num+n);

    func15663(0);

    return 0;
}