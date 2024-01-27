#include <iostream>
#include <cstring>

using namespace std;

string func(char a[], char b[]){
    string pos = "Possible", impos = "Impossible";

    int arrA[26], arrB[26]; // 97 ~ 

    fill(arrA, arrA+26, 0);
    fill(arrB, arrB+26, 0);

    for(int i = 0; i < (int)strlen(a); ++i){
        arrA[a[i] - 97]++;
        arrB[b[i] - 97]++;
    }

    for(int i = 0; i < 26; ++i){
        if(arrA[i] != arrB[i]){
            return impos;
        }
    }

    return pos;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string result;

    cin >> N;

    for(int i = 0; i < N; ++i){
        char a[1000], b[1000];

        cin >> a >> b;

        result+=func(a,b);
        result+="\n";
    }

    cout<<result;
    return 0;
}