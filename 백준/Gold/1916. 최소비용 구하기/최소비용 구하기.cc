#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    priority_queue <pair<int,int>> pq;
    vector <pair<int,int>> graph[1001];
    int N,M;
    int dist[1001];
    cin>>N>>M;
    for(int i=1; i<=N; i++) dist[i] = INF;
    for(int _=0; _<M; _++){
        int s,e,w;
        cin>>s>>e>>w;
        graph[s].push_back({w,e});
    }
    int start,end;
    cin>>start>>end;
    dist[start] = 0;
    pq.push({0,start});
    while (!pq.empty())
    {
        int currentWeight = -(pq.top().first);
        int currentCity =  pq.top().second;
        
        pq.pop();
        if(currentWeight > dist[currentCity]) continue; 
        for(auto &arriveCity : graph[currentCity]){
            int arrivecityName = arriveCity.second;
            int arriveWeight = currentWeight + arriveCity.first;
            if( arriveWeight < dist[arrivecityName]) {
                dist[arrivecityName] = arriveWeight;
                pq.push({-arriveWeight,arrivecityName});
            }
            
        }
    }
    cout<<dist[end];


    return 0;
}