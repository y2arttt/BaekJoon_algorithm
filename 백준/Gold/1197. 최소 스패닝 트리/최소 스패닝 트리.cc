#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int start;
    int end;
    int weight;
    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};

struct CompareEdge {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};

priority_queue<Edge, vector<Edge>, CompareEdge> pq;
vector<int> parents(10001, -1);

int find(int n) {
    if (parents[n] == -1) return n;
    return parents[n] = find(parents[n]);
}

void uni(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parents[rootB] = rootA;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        pq.push(Edge(s, e, w)); 
    }

    int totalWeight = 0;
    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();
        if (find(edge.start) != find(edge.end)) {
            uni(edge.start, edge.end);
            totalWeight += edge.weight;  
        }
    }
    cout << totalWeight;

    return 0;
}
