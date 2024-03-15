#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10], isUsed[10000];

void func15656(int k, int inArr[]){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; ++i){
        int val = inArr[i];

        arr[k] = val;

        for(int j = i; j >= 0; --j)
            isUsed[inArr[j]] = true;

        func15656(k + 1, inArr);
        
        for(int j = i; j >= 0; --j)
            isUsed[inArr[j]] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int in[n];

    for(int i = 0; i < n; ++i)
        cin >> in[i];

    sort(in, in + n);

    func15656(0, in);

    return 0;
}