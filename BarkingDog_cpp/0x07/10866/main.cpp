#include <iostream>
#include <deque>
#include <string>

using namespace std;

void func(deque<string> &dq, string command, string &result){
    if(command == "size"){
        result += to_string(dq.size());
        result += "\n";
    }
    else if(command == "empty"){
        result += to_string(dq.empty());
        result += "\n";
    }
    else if(command == "front"){
        if(!dq.empty()){
            result+=dq.front();
            result+="\n";
        }else{
            result+="-1\n";
        }
    }
    else if(command == "back"){
        if(!dq.empty()){
            result+=dq.back();
            result+="\n";
        }else{
            result+="-1\n";
        }
    }else{ // push & pop
        unsigned int idx = command.find("_");
        string cmd = command.substr(0, idx);

        if(cmd == "push"){
            unsigned int spaceIdx = command.find(" ");
            string cmd1 = command.substr(0, spaceIdx);
            string cmd2 = command.substr(spaceIdx+1, command.size());

            string tmp_cmd = cmd1.substr(cmd1.find("_")+1, cmd1.size());

            if(tmp_cmd == "front"){
                dq.push_front(cmd2);
            }else{
                dq.push_back(cmd2);
            }
        }else{ // pop
            string cmd2 = command.substr(idx+1, command.size());
            if(cmd2 == "front"){
                if(!dq.empty()){
                    result += dq.front();
                    result += "\n";

                    dq.pop_front();
                }else{
                    result += "-1\n";
                }
            }else{
                if(!dq.empty()){
                    result += dq.back();
                    result += "\n";

                    dq.pop_back();
                }else{
                    result += "-1\n";
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<string> dq;
    string result;
    int n;
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string command;

        getline(cin, command);
        
        func(dq, command, result);
    }

    cout<< result;

    return 0;
}