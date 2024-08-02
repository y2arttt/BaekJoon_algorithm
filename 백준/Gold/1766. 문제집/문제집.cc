#include <iostream>
#include <queue>
#include <vector>
#include <cstring>


using namespace std;



int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> link(n + 1);
    vector <int> in(n+1,0);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        link[a].push_back(b);
        in[b]++;//b를 풀기 전 풀어야 할 문제의 개수
    }
    priority_queue <int> pq;
    for(int i=1; i<=n; i++){
        if(in[i] == 0) pq.push(-i);
    }
    while (! pq.empty())
    {
        int node =  -pq.top();
        pq.pop();
        cout<<node<<" ";
        for(auto& l : link[node]){
            in[l]--;
            if(in[l] == 0) pq.push(-l);
        }
    }
    

    return 0;
}