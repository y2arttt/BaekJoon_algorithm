#include <iostream>
#include <vector>
#include <cstring>
#define INF 1e10
using namespace std;


int main() {
    int tc, n,m,w;
    cin >> tc;
    for(int _=0; _<tc; _++){
        bool cycle = false;
        cin>>n>>m>>w;
        vector<vector<pair<int,int>>> maps(n+1);
        vector<long long> dist(n+1,INF);

        for(int i=0; i<m; i++){
            int s,e,t;
            cin>>s>>e>>t;
            maps[s].push_back({e,t});
            maps[e].push_back({s,t});
        }
        for(int i=0; i<w; i++){
            int s,e,t;
            cin>>s>>e>>t;
            maps[s].push_back({e,-t});
        }
        dist[1] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(auto& m:maps[j]){
                    int next = m.first;
                    int time = m.second;
                    if(dist[next] > dist[j] + time){    
                        dist[next] = dist[j] + time;
                        if(i == n) cycle = true; 
                    }
                }
            }
        }
        if(cycle) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}