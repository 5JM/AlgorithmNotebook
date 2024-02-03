#include <iostream>
#include <stack>

using namespace std;

int func(string str){
    stack<char> s;
    int result = 1;

    for(int i = 0; i < str.size(); ++i){
        char curChar = str[i];
        int isInValid = 0;

        switch (curChar)
        {
            case 'A':
                if(!s.empty()){
                    if(s.top() == 'A'){
                        s.pop();
                    }else{
                        s.push(curChar);
                    }
                }else{
                    s.push(curChar);
                }
                break;
            
            default: // B
                if(!s.empty()){
                    if(s.top() == 'B'){
                        s.pop();
                    }else{
                        s.push(curChar);
                    }
                }else{
                    s.push(curChar);
                }
                break;
        }

        if(isInValid){
            result = 0;
            break;
        }
    }

    if(!s.empty())
        result = 0;

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, result = 0;
    cin>> n;

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string str;
        getline(cin, str);

        result += func(str);
    }

    cout<< result;
    return 0;
}