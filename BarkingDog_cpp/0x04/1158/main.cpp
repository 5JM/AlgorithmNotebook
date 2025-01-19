#include <iostream>
#include <list>

using namespace std;

void make3rdIter(list<int> &inList, list<int>::iterator &it, int k){
    for(int i = 0; i < k-1; ++i){
        if(it == inList.end()) it = inList.begin();
        it++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    list<int> inList;
    list<int>::iterator iter;

    for(int i = 1; i <= n; ++i){
        inList.push_back(i);
    }

    iter = inList.begin();

    cout<< "<";
    while(!inList.empty()){
        make3rdIter(inList, iter, k);

        if(iter == inList.end()) iter = inList.begin();
        
        if(inList.size() > 1)
            cout<< *iter<<", ";        
        else
            cout<< *iter<<">";

        iter = inList.erase(iter);
    }

    return 0;
}