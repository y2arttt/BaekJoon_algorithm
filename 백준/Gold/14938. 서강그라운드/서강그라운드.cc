#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,r;
    cin >> n>>m>>r;
    vector<int> items(n+1);
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));
    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }
    for(int i=1; i<=n; i++){
        cin>>items[i];
    }
    for(int i=0; i<r; i++){
        int a,b,l;
        cin>>a>>b>>l;
        dist[a][b] = l;
        dist[b][a] = l;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                int  pass = dist[i][k] + dist[k][j];
                if( dist[i][j] > pass){
                    dist[i][j] = pass;
                }
            }
        }
    }   

    int maxx = 0;
    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=n; j++){
            if(dist[i][j] <= m) sum+=items[j];
        }
        maxx = max(maxx,sum);
    }
    cout<<maxx;
    return 0;
}