#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, v;
    int arrPos[101], arrNeg[101];

    fill(arrPos, arrPos+101, 0);
    fill(arrNeg, arrNeg+101, 0);
    
    cin >> N;

    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        if(tmp >= 0)
            arrPos[tmp]++;
        else{
            arrNeg[-1*tmp]++;
        }
    }

    cin >> v;

    if(v >= 0) cout<< arrPos[v];
    else cout<< arrNeg[-1*v];

    return 0;
}