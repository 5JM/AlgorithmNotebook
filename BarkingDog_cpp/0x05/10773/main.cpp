#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, sum = 0;
    stack<int> s;

    cin >> k;

    for(int i = 0; i < k; ++i){
        int tmp;
        cin >> tmp;

        if(tmp == 0){
            if(!s.empty()){
                s.pop();
            }
        }else{
            s.push(tmp);
        }
    }

    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }

    cout<< sum;

    return 0;
}