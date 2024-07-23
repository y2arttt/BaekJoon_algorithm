#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;
    int dist[20005];
    for(int i=1; i<=V;i++) dist[i] = INF;
    priority_queue <pair<int,int>> pq;
    vector<pair<int,int>> graph[20004];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    pq.push({0,K});
    dist[K] = 0;
    while (!pq.empty()) {       
        int current_dist = -(pq.top().first); //최소힙 = 음수임
        int current = pq.top().second;
        pq.pop();
        if (current_dist > dist[current]) continue;

        for (auto &edge : graph[current]) {
            int next = edge.first;//간선
            int weight = edge.second;//가중치

            int new_dist = dist[current] + weight; //현재 거리 + 간선의 가중치
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({-(new_dist), next});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout<<"INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}