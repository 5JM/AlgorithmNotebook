#include <iostream>
#include <stack>

using namespace std;

string func(string str){
    string result = "YES\n";
    stack<char> s;

    for(int i = 0; i < str.size(); ++i){
        char curChar = str[i];
        int isInValid = 0;

        switch (curChar)
        {
            case '(':
                s.push(curChar);

                break;
            
            default: // ')'
                if(!s.empty() && s.top()=='('){
                    s.pop();
                }else{
                    isInValid = 1;
                }
                break;
        }

        if(isInValid){
            result = "NO\n";
            break;
        } 
    }

    if(!s.empty()) result = "NO\n";
        
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin.ignore();

    string result;
    stack<char> s;

    for(int i = 0; i < n; ++i){
        string str;
        getline(cin, str);

        result += func(str);
    }
    cout<<result;
    return 0;
}