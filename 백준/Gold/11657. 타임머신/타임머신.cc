#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX
using namespace std;


int main() {
    int N,M;
    bool cycle = false;
    cin>>N>>M;
    vector<vector<pair<int, int>>> maps(N + 1);
    vector<long long> dist(N + 1, INF); //dist를 longlong으로 안해서 틀림
    dist[1]=0;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        maps[a].push_back({b,c});
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(auto& map : maps[j]){
                int next = map.first;
                int weight = map.second;
                if(dist[j] != INF && dist[next] > dist[j] + weight){
                    dist[next] = dist[j] + weight;
                    if(i == N) cycle = true;
                }
            }
        }
    }
    if(cycle) cout<<-1;
    else {
        for(int i=2; i<=N; i++){
            if(dist[i] == INF) cout<<-1<<'\n';
            else cout<<dist[i]<<'\n';
        }
    }
    return 0;
}