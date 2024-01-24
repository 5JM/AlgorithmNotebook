#include <iostream>
#include <algorithm>

using namespace std;

void insert(int idx, int num, int arr[], int& len){
    for(int i = len; i > idx; --i) {
        arr[i] = arr[i-1];
    }

    arr[idx] = num;

    len++;
}

void erase(int idx, int arr[], int& len){
    
    for(int i = idx+1; i < len; ++i) {
        arr[i-1] = arr[i];
    }

    len--;
}

void printArr(int arr[], int& len){
    for(int i = 0; i < len; ++i) cout<< arr[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;

    int arr2[21];
    int len2 = 21;

    insert(3, 60, arr, len); // 10 50 40 60 30 70 20

    printArr(arr, len);

    erase(4, arr, len); // 10 50 40 60 70 20

    printArr(arr, len);

    // 배열을 특정 값으로 채울 때 -> algorithm.h
    fill(arr2, arr2+21, 1);

    printArr(arr2, len2);

    return 0;
}