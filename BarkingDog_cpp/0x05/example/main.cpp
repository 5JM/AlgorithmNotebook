#include <iostream>
#include <stack>

using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
    dat[pos++] = x;
}

void pop(){
    if(pos >= 0) pos--;
}

int top(){
    return dat[pos-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    push(5); 
    push(4); 
    push(3);

    cout << top() << '\n'; // 3

    pop(); 
    pop();

    cout << top() << '\n'; // 5

    push(10); 
    push(12);

    cout << top() << '\n'; // 12

    pop();

    cout << top() << '\n'; // 10

    return 0;
}