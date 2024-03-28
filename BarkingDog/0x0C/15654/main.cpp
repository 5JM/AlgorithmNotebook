#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10000];

void func15654(int k, int inArr[]){
    if(k == m){
        for(int i = 0; i < m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; ++i){
        int val = inArr[i];

        if(!isUsed[val]){
            arr[k] = val;

            isUsed[val] = true;


            func15654(k + 1, inArr);
            
            isUsed[val] = false;
        }
    }
}

void func15654UsePermu(int inArr[]){
    int flags[n];

    fill(flags, flags+m, 0);
    fill(flags+m, flags+n, 1);

    vector<vector<int> > res;

    do{
        vector<int> tmp;

        for(int i = 0; i < n; ++i){
            if(!flags[i]) tmp.push_back(inArr[i]);
        }
        do{
            res.push_back(tmp);
        }while(next_permutation(tmp.begin(), tmp.end()));

    }while(next_permutation(flags, flags+n));

    sort(res.begin(), res.end());

    for(vector<vector<int> >::iterator it = res.begin(); it != res.end(); ++it){
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
            cout<< *it2 << ' ';
        }
        cout<<'\n';
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

    // back tracking
    // func15654(0, in);

    // next_permutaion
    func15654UsePermu(in);

    return 0;
}