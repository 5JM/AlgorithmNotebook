#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

string dqToString(deque<int> &dq, int mode){
    string result = "[", tmp;

    while(!dq.empty()){
        if(mode){ // reverse
            tmp = to_string(dq.back());
            dq.pop_back();
        }
        else{ // normal
            tmp = to_string(dq.front());
            dq.pop_front();
        }
        
        result += tmp;
        result += ",";
    }
    if(result.size()>1)
        result.pop_back();
    result += "]";

    return result;
}

void getArr(string str, int n, deque<int> &dq){
    string tmp = str.substr(1, str.size()-1);
    string num ;
    
    for(string::iterator it = tmp.begin(); it != tmp.end(); ++it){
        if(*it != ','){
            if(*it == ']' && !num.empty()){
                stringstream ss;
                int tmpNum;

                ss << num;
                ss >> tmpNum;
                dq.push_back(tmpNum);
            }else{
                num += *it;
            }
        }
        else{
            stringstream ss;
            int tmpNum;

            ss << num;
            ss >> tmpNum;

            dq.push_back(tmpNum);

            num = "";
        }
    }
}

string func(string command, deque<int> &dq){
    int reverseCnt = 0, mode;

    for(string::iterator it = command.begin(); it != command.end(); it++){
        if(*it == 'R'){
            reverseCnt++;
        }else{
            if(dq.empty()) return "error";

            if(reverseCnt % 2 == 0){
                // no reverse
                dq.pop_front();
            }else{
                // reverse
                dq.pop_back();
            }
        }
    }

    if(reverseCnt % 2 == 0) mode = 0;
    else mode = 1;

    return dqToString(dq, mode);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string result;
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i){
        string command, arr;
        int arrN;
        deque<int> dq;

        cin >> command;
        
        cin >> arrN;
        
        cin >> arr;

        getArr(arr, arrN, dq);
        
        result += func(command, dq);
        result +="\n";
    }

    cout<< result;
    return 0;
}