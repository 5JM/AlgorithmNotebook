#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string result;

    while(1){
        stack<char> s;
        string str;

        getline(cin, str);
        
        if(str=="."){
            cout<<result;
            break;
        }
            

        for(string::iterator it = str.begin(); it != str.end(); ++it){
            char tmp = *it;
            string _result = "yes";

            switch(tmp){
                case '(':
                    s.push(tmp);
                    break;
                case '[':
                    s.push(tmp);
                    break;

                case ')':
                    if(s.empty()) {
                        _result = "no";
                        break;
                    }
                    if(s.top() == '(') s.pop();
                    else _result = "no";
                    break;

                case ']':
                    if(s.empty()){
                        _result = "no";
                        break;
                    }
                    if(s.top() == '[') s.pop();
                    else _result = "no";
                    break;

                default:
                    break;
            }

            if(_result == "no"){
                result += _result;
                break;
            }
            
            
            if(tmp == '.'){
                if(s.empty()) result += _result;
                else result += "no";

                break;
            }
        }
        result+="\n";
    }
    


    return 0;
}