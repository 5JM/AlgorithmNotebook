#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    stack<char> s;
    int result = 0, tmp = 1;

    getline(cin, str);
    
    for(string::iterator it = str.begin(); it != str.end(); ++it){
        char currentChar = *it;
        int isInvalid = 0;

        switch (currentChar){
            case '(':
                s.push(currentChar);
                tmp *= 2;

                break;

            case '[':
                s.push(currentChar);
                tmp *= 3;

                break;

            case ')':
                if(!s.empty() && s.top() == '('){
                    if(*(it-1) == '('){
                        result += tmp;
                    }
                    tmp/=2;

                    s.pop();
                }else{ // inValid
                    isInvalid = 1;
                }

                break;

            default: // ]
                if(!s.empty() && s.top() == '['){
                    if(*(it-1) == '['){
                        result += tmp;
                    }
                    tmp/=3;

                    s.pop();
                }else{ // inValid
                    isInvalid = 1;
                }

                break;
        }

        if(isInvalid){
            result = 0;
            break;
        }
        
    }
    if(!s.empty())
        result = 0;
    cout<< result;
    return 0;
}