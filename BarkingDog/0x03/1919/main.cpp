#include <iostream>
#include <cstring>

using namespace std;

int abs(int num){
    if(num >= 0) return num;
    else return -1*num;
}

int func(char a[], char b[]){
    int nA = (int)strlen(a), nB = (int)strlen(b), result = 0;
    int arrA[26], arrB[26];

    fill(arrA, arrA+26, 0);
    fill(arrB, arrB+26, 0);

    for(int i = 0; i<nA; ++i){
        arrA[a[i]-97]++;
    }

    for(int i = 0; i<nB; ++i){
        arrB[b[i]-97]++;
    }

    for(int i = 0; i < 26; ++i){
        int gap = abs(arrA[i]-arrB[i]);
        result += gap;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char a[1001], b[1001];

    cin >> a;
    cin >> b;

    cout << func(a, b);

    return 0;
}