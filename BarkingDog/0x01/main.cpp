#include <iostream>
#include "func.h"

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

    insert(3, 60, arr, len); // 10 50 40 60 30 70 20

    printArr(arr, len);

    erase(4, arr, len); // 10 50 40 60 70 20

    printArr(arr, len);

    return 0;
}