#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int p[32001]={0,};
    cin>>n>>m;
    vector<vector<int>> edge(32000,vector<int>());
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        p[b]++;
    }
    priority_queue <int> pq;
    for(int i=1; i<=n; i++){
        if(p[i] == 0) pq.push(i);
    }
    while (!pq.empty())
    {
        int student = pq.top();
        pq.pop();
        cout<<student<<' ';
        for(auto& e: edge[student]){
            p[e]--;
            if(p[e] == 0) pq.push(e);
        }
    }
    

    return 0;
}
