#include <iostream>

using namespace std;



int main()
{
    int N,S;
    cin >> N >> S;
    int X[100000];
    for (int i=0; i<N; i++){
        cin>> X[i];
    }
    int sum = 0;
    int start=0;
    int cnt = 0;
    int minCnt = 100001;
    for (int i=0; i<N; i++){
        cnt++;
        sum += X[i];
        while(sum >= S){
            if(minCnt > cnt) minCnt = cnt;
            cnt--;
            sum -= X[start++];
        }
    }
    if(minCnt == 100001) cout<<0;
    else cout<<minCnt;
    return 0;
}