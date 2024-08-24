#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip> 
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

vector<vector<float>> maps(1001,vector<float>(2,-1));
priority_queue<Edge, vector<Edge>, CompareEdge> pq;
vector<int> parents(1001);


int find(int n) {
    if (parents[n] == n) return n;
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
    //prarents값 초기화
    for(int i = 0; i < 1001; i++) {
    parents[i] = i;
    }

    int n,m;
    cin >>n>>m;
    for (int i = 0; i < n; i++) {
        cin>>maps[i][0]>>maps[i][1];
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        uni(a-1,b-1);//index는 0부터 시작
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ 
            if(find(i) == find(j))continue;
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
    cout << fixed << setprecision(2) << totalWeight << endl;


    return 0;
}