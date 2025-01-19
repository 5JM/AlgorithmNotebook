#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void traverse(){
    int cur = nxt[0];

    while(cur != -1){
        cout<< dat[cur] << " ";
        cur = nxt[cur];
    }
}

void insert(int addr, int num){
    int postTmpAddr = nxt[addr];

    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = postTmpAddr;

    if(postTmpAddr != -1) pre[postTmpAddr] = unused;
    nxt[addr] = unused;

    unused++;
}

void erase(int addr){
    int prevTmpAddr = pre[addr];
    int postTmpAddr = nxt[addr];

    nxt[prevTmpAddr] = postTmpAddr;
    if(postTmpAddr != -1) pre[postTmpAddr] = prevTmpAddr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    return 0;
}