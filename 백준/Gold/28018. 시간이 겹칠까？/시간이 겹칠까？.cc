#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int time[1000001];
    memset(time,0,sizeof(time));
    int N,M=0;
    cin>>N;
    for(int i=0; i<N; i++){
        int S,F;
        cin>>S>>F;
        time[S]++;
        time[F+1]--;
        M=max(M,F);
    }
    for(int i=1; i<=M+1; i++){
        time[i] = time[i] + time[i-1];
    }
    int Q,q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        cin>>q;
        cout<<time[q]<<'\n';
    }

    return 0;
}