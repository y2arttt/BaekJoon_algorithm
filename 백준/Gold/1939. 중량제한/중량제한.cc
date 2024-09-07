#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> edge(n + 1); // [start] first:end second:w
    int max_weight = 0;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c}); 
        max_weight = max(max_weight, c);
    }
    
    int s, e;
    cin >> s >> e;

    int min_weight = 1;
    
    while (min_weight <= max_weight) {
        int current_weight = (min_weight + max_weight) / 2;
        
        vector<bool> visit(n + 1, false);
        visit[s] = true;

        queue<int> q;
        q.push(s);

        bool can_reach = false;
        
        while (!q.empty()) {
            int start = q.front();
            q.pop();

            if (start == e) {
                can_reach = true;
                break;
            }

            for (auto& edg : edge[start]) {
                int next = edg.first;
                int w = edg.second;

                if (!visit[next] && w >= current_weight) {
                    visit[next] = true;
                    q.push(next);
                }
            }
        }

        if (can_reach) min_weight = current_weight + 1;
        else max_weight = current_weight - 1;
    }

    cout << max_weight;

    return 0;
}
