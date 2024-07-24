#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    int map[N+1][N+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) map[i][j] = 0;
            else map[i][j] = INF;
        }
    }
    for(int i=0; i<M; i++){
        int s,e,w;
        cin>>s>>e>>w;
        map[s][e] = min(map[s][e], w); //같은 노선을 여러번 받는 다는 것을 간과했었음
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[i][k] != INF && map[k][j] != INF)
                    map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[i][j] == INF) cout << "0 ";
            else cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}