#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    getline(cin, str);

    stack<char> s;
    int cnt = 0;

    for(string::iterator it = str.begin(); it != str.end(); ++it){
        char tmp = *it;

        switch (tmp)
        {
            case '(':
                s.push(tmp);

                break;

            case ')':
                if(!s.empty()){ 
                    if(*(it-1) == '('){// razer
                        s.pop();

                        cnt+=s.size();

                    }else{ // end of bar
                        s.pop();

                        cnt++;
                    }
                    
                }

                break;

            default:
                break;
        }

    }

    cout<<cnt;

    return 0;
}