#include <iostream>
#include <string>

using namespace std;

int k, num[13], arr[13];
bool isUsed[13];
string result;

void func6603(int l){
    if(l == 6){
        for(int i = 0; i < 6; ++i){
            result+= to_string(arr[i]);
            result+= ' ';
        }
        result+='\n';
        return;
    }
    
    for(int i = 0; i < k; ++i){
        if(!isUsed[i]){
            arr[l] = num[i];

            for(int j = i; j >= 0; --j)
                isUsed[j] = true;

            func6603(l+1);

            for(int j = i; j >= 0; --j)
                isUsed[j] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> k;

        if(k == 0) break;

        for(int i = 0; i < k; ++i)
            cin >> num[i];

        func6603(0);

        result+='\n';
    }
    
    cout<< result;
    return 0;
}