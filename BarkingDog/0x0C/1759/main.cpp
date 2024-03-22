#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char arr[17], chars[17];

bool isMoem(){
    int cnt = 0;

    for(int i = 0; i < l; ++i){
        char ch = arr[i];

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            cnt++;
        }
    }

    if(cnt >= 1 && l - cnt >= 2)
        return true;
    else
        return false;
}

void func1759(int k, int start){
    if(k == l && isMoem()){
        for(int i = 0; i < l; ++i){
            cout << arr[i];
        }
        cout<< '\n';
        return ;
    }


    for(int i = start; i < c; ++i){
        arr[k] = chars[i];
        
        func1759(k+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for(int i = 0; i < c; ++i)
        cin >> chars[i];
    
    sort(chars, chars+c);

    func1759(0, 0);

    return 0;
}