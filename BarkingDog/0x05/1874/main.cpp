#include <iostream>
#include <stack>

using namespace std;

void pushEmpty(stack<int> &s, int num, int arr[], string &result){
    for(int i = 1; i <= num; ++i){
        if(arr[i] == 1 ){
            s.push(i);

            result+="+\n";

            arr[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    string result;
    int n;

    cin >> n;
    int arr[n+1];

    for(int i = 1; i <=n; ++i) arr[i] = 1;

    try{
        for(int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;

            if(s.empty()){
                pushEmpty(s, tmp, arr, result);
            }
            
            while(s.top() != tmp){
                if(s.top() < tmp ){
                    pushEmpty(s, tmp, arr, result);
                }else{
                    throw 1; // nullptr -> c++ 11 부터 지원...
                }
            }

            if(!s.empty()){
                s.pop();

                result+="-\n";

                arr[tmp] = 0;
            }

        }
        cout<< result;

    } catch(...){
        cout<<"NO";
    }

    return 0;
}