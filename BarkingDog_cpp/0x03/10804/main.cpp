#include <iostream>

using namespace std;

void func(int arr[], int a, int b){
    for(int i = 0; i < (b-a+1)/2; ++i){
        int tmp = arr[a + i];

        arr[a + i] =  arr[b-i];
        arr[b-i] = tmp;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];
    int a, b;

    for(int i = 1; i < 21; ++i) arr[i] = i;

    for(int i = 0; i < 10; ++i){
        cin >> a >> b;

        func(arr, a, b);
    }
        
    for(int i = 1; i < 21; ++i){
        cout<< arr[i] << " ";
    }

    return 0;
}