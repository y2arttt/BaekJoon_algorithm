#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip> 
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
priority_queue <Edge,vector<Edge>,CompareEdge> pq;
vector<int> parents(200001); 
vector<vector<int>> maps(200001,vector<int>(2,-1));


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

//거리 비교 함수
int dist(int sx, int sy,int es,int ey){
    return sqrt((sx-es)*(sx-es) + (sy-ey)*(sy-ey));
}

int main() {
    

    int n,m;
    while (true)
    {
        
        cin >>n>>m;
        if(n==0 && m==0) break;
        
        //초기화
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        
        for (int i = 0; i < m; i++) {
            int s,e,w;
            cin>>s>>e>>w;
            pq.push({s,e,w});
        }

        int result = 0;
        //크루스칼 알고리즘
        while (!pq.empty()) {
            Edge edge = pq.top();
            pq.pop();
            if (find(edge.start) != find(edge.end)) {
                uni(edge.start, edge.end);
            }
            else{
                result += edge.weight;
            }
        }
        cout  << result<<'\n';


    
    }
    
    
    return 0;
}