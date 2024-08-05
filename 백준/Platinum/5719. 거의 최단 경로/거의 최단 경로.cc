#include <iostream>
#include <climits> 
#include <vector>
#include <queue>
#define INF LLONG_MAX

using namespace std;

int s, e;
vector<vector<pair<int, int>>> maps(501);
vector<vector<int>> reverseMap(501);

long long dijkstra() {
    vector<long long> dist(501, INF);
    priority_queue<pair<long long, int>> pq;
    dist[s] = 0;
    pq.push({0, s});
    
    while (!pq.empty()) {
        long long w = -pq.top().first;
        int c = pq.top().second;
        pq.pop();
        
        if (dist[c] < w) continue;
        
        for (auto& m : maps[c]) {
            int next = m.first;
            long long nw = m.second;
            if (nw == -1) continue; // 간선이 제거된 경우
            if (dist[next] > w + nw) {
                dist[next] = w + nw;
                pq.push({-dist[next], next});
                reverseMap[next].clear();
                reverseMap[next].push_back(c);
            } else if (dist[next] == w + nw) {
                reverseMap[next].push_back(c);
            }
        }
    }
    
    return dist[e];
}

void delMaps() {
    vector<bool> visited(501, false);
    queue<int> r;
    r.push(e);
    visited[e] = true;
    
    while (!r.empty()) {
        int c = r.front();
        r.pop();
        
        for (auto rm : reverseMap[c]) {
            for (auto& edge : maps[rm]) {
                if (edge.first == c) {
                    edge.second = -1;
                    break;
                }
            }
            if (!visited[rm]) {
                visited[rm] = true;
                r.push(rm);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        maps = vector<vector<pair<int, int>>>(501);
        reverseMap = vector<vector<int>>(501);
        
        cin >> s >> e;
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            maps[u].push_back({v, p});
        }
        
        long long ans = dijkstra();
        delMaps();
        long long ans2 = dijkstra();
        
        if (ans2 == INF) cout << -1 << '\n';
        else cout << ans2 << '\n';
    }
    
    return 0;
}
