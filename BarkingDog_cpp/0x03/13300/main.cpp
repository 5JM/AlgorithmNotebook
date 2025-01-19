#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, manN = 0, womanN = 0, result = 0;
    int arrM[6], arrW[6];

    fill(arrM, arrM+6, 0);
    fill(arrW, arrW+6, 0);

    cin >> N >> K;

    for(int i = 0; i < N; ++i){
        int gender, grade;
        cin>> gender >> grade;

        if(gender) {
            arrM[grade-1]++;
        }
        else {
            arrW[grade-1]++;
        }
    }

    for(int i = 0; i < 6; ++i){
        result += arrM[i] / K;
        if(arrM[i] % K != 0) result++;

        result += arrW[i] / K;
        if(arrW[i] % K != 0) result++;
    }

    // print info
    // cout<<"        Man     Woman\n";
    // for(int i = 0; i < 6; ++i){
    //     cout<< "grade "<<i+1<<" " << arrM[i]<< "    "<<arrW[i]<<"\n";
    // }

    cout<< result;

    return 0;
}