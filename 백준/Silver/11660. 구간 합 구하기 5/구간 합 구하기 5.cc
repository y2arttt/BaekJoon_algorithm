#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int T[N+1][N+1];
    memset(T,0,sizeof(T));
    for(int i = 1; i <=N; i++){
        for(int j=1; j<=N; j++){
            cin>>T[i][j];
            T[i][j] = T[i][j] + T[i-1][j]+ T[i][j-1] - T[i-1][j-1];
        }
    }
    while (M--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int result = T[x2][y2] - T[x1-1][y2] - T[x2][y1-1] + T[x1-1][y1-1];
        cout<<result<<'\n';

    }
    


    return 0;   
}