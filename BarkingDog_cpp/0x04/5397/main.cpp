#include <iostream>
#include <list>

using namespace std;


string func(string inStr){
    list<char> inList;
    list<char>::iterator cursor;
    string result;
    
    cursor = inList.begin();

    for(string::iterator it = inStr.begin(); it != inStr.end(); ++it){
        char tmp = *it;

        if(tmp == '<'){
            if(cursor != inList.begin()) cursor--;
        }else if(tmp == '>'){
            if(cursor != inList.end()) cursor++;
        }else if(tmp == '-'){
            if(cursor != inList.begin())
                cursor = inList.erase(--cursor);  
        }else{
            inList.insert(cursor, tmp);
        }
    }

    for(list<char>::iterator it = inList.begin(); it != inList.end(); ++it){
        result += (*it);
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    
    cin >> n;

    string results[n]; 

    for(int i = 0; i< n; ++i){
        string tmp;
        cin >> tmp;

        results[i] = func(tmp);
    }

    for(int i = 0; i< n; ++i){
        cout<< results[i] << "\n";
    }

    return 0;
}