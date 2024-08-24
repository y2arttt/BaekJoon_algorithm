#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Edge {
    int start;
    int end;
    double weight;
    Edge(int s, int e, double w) : start(s), end(e), weight(w) {}
};

struct CompareEdge {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};

vector<vector<float>> maps(101,vector<float>(2,-1));
priority_queue<Edge, vector<Edge>, CompareEdge> pq;
vector<int> parents(101, -1);

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

double dist(double sx, double sy,double es,double ey){
    return sqrt((sx-es)*(sx-es) + (sy-ey)*(sy-ey));
}

int main() {
    int m;
    cin >>m;
    for (int i = 0; i < m; i++) {
        cin>>maps[i][0]>>maps[i][1];
    }
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){ //중복 간선 최소화
            if(i==j)continue;
            pq.push({i,j,dist(maps[i][0],maps[i][1],maps[j][0],maps[j][1])});
        }
    }

    double totalWeight = 0;
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