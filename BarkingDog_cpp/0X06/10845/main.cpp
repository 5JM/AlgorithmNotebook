#include <iostream>
#include <queue>
#include <string>

using namespace std;

void func(queue<string> &q, string command, string &result){
    if(command == "pop"){
        if(!q.empty()){
            result += q.front();
            result += "\n";
            q.pop();
        }else{
            result += "-1\n";
        }
    }else if(command == "size"){
        result += to_string(q.size());
        result += "\n";
    }
    else if(command == "empty"){
        result += to_string(q.empty());
        result += "\n";
    }
    else if(command == "front"){
        if(!q.empty()){
            result+=q.front();
            result+="\n";
        }else{
            result+="-1\n";
        }
    }
    else if(command == "back"){
        if(!q.empty()){
            result+=q.back();
            result+="\n";
        }else{
            result+="-1\n";
        }
    }else{ // push x
        unsigned int idx = command.find(" ");
        string cmd1 = command.substr(0, idx);
        string cmd2 = command.substr(idx+1, command.size());

        q.push(cmd2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<string> q;
    string result;
    int n;
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string command;

        getline(cin, command);
        
        func(q, command, result);
    }

    cout<< result;

    return 0;
}