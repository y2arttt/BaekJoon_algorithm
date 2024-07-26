#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> edge[100001];
bool visited[100001];
int maxs;
int farthest_node;

void dfs(int root, int weight) {
    visited[root] = true;
    if (weight > maxs) {
        maxs = weight;
        farthest_node = root;
    }
    for (auto& e : edge[root]) {
        int nextWeight = e.first;
        int node = e.second;
        if (!visited[node]) {
            dfs(node, weight + nextWeight);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i < N; i++) {
        int p, c, w;
        cin >> p;
        while (true)
        {
            cin>>c;
            if(c == -1) break;
            cin>>w;
            edge[p].push_back({w, c});
            edge[c].push_back({w, p});
        }
        

    }

    
    fill(visited, visited + N + 1, false);
    maxs = 0;
    dfs(1, 0);

    fill(visited, visited + N + 1, false);
    maxs = 0;
    dfs(farthest_node, 0); 

    cout << maxs;
    return 0;
}