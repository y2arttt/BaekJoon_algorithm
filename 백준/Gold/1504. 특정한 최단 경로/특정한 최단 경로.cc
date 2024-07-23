#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std;
int map[801][801];
int N;
int dijkstra(int start,int end){
    int weight[801];
    for(int i=1; i<=N; i++) weight[i] = INF;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    weight[start] = 0;
    while (!pq.empty())
    {
        int currentW = pq.top().first;
        int currentN = pq.top().second;
        pq.pop();
        if(currentW > weight[currentN]) continue;
        for(int i=1; i<=N; i++){
            if(map[currentN][i] != 0){
                int arriveW = currentW + map[currentN][i];
                if(arriveW < weight[i]){
                    weight[i] = arriveW;
                    pq.push({arriveW,i});
                }
            }
        }
    }
    return weight[end];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int E,v1,v2;
    cin>>N>>E;
    while (E--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        map[a][b]=c;
        map[b][a]=c;
    }
    cin>>v1>>v2;
    int sTv1 = dijkstra(1,v1);
    int sTv2 = dijkstra(1,v2);
    int v1Tv2 = dijkstra(v1,v2);
    if(v1Tv2 == INF){
        cout<<-1;
    }
    else{
        int minx = INF;
        int v1Tn = dijkstra(v1,N);
        int v2Tn = dijkstra(v2,N);
        if(sTv1 != INF && v2Tn != INF) minx=min(minx,sTv1+v1Tv2+v2Tn);
        if(sTv2 != INF && v1Tn != INF) minx=min(minx,sTv2+v1Tv2+v1Tn);
        if(minx == INF) cout<<-1;
        else cout<<minx;
    }
    

    return 0;
}