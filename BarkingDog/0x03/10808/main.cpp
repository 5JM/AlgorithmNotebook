#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int arr[], int& len){
    for(int i = 0; i < len; ++i) cout<< arr[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int arr[26];
    int len = 26;

    fill(arr, arr+len, 0);


    cin >> s;

    // a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    // 총 26 

    while(!s.empty()){
        char tmp =  s.back();

        for(int i = 97; i < 97+len; ++i){
            if(tmp == i){
                arr[i - 97]++; 
            }
        }

        s.pop_back();
    }

    printArr(arr, len);

    return 0;
}