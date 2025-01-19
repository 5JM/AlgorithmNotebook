#include <iostream>
#include <list>
#include <string>

using namespace std;

void func(list<char> &str, string command, list<char>::iterator &cursor){
    if(command.size() > 1){
        char addChar = command[2];

        str.insert(cursor, addChar);

    }else{
        if(command == "L"){
            // move cursor to left
            if(cursor != str.begin())
                cursor--;

        }else if(command == "D"){
            // move cursor to right
            if(cursor != str.end())
                cursor++;
        }else{
            // delete char on to the left of the cursor
            if(cursor != str.begin())
                cursor = str.erase(--cursor);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string text;
    string command;

    list<char> textList;
    int M;

    list<char>::iterator cursorIter;

    cin >> text;
    cin >> M;

    for(int i = 0; i < text.size(); ++i){
        textList.push_back(text[i]);
    }

    cursorIter = textList.end();

    cin.ignore();

    for(int i = 0; i < M; ++i){
        getline(cin, command);

        func(textList, command, cursorIter);
    }
    
    for(list<char>::iterator it = textList.begin(); it!=textList.end();++it){
        cout<< *it;
    }

    return 0;
}