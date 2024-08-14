#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct ed
{
    int s,e,w;
};

vector<int> parents(1001);
vector<ed> edge(100001);



bool compareEdges(const ed& a, const ed& b) {
    return a.w < b.w;
}

int find(int n){
    if(parents[n] == n) return n;
    return parents[n] = find(parents[n]);
}

void uni(int s, int e){
    int S = find(s);
    int E = find(e);
    parents[E]=S; 
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    int c=0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parents[i] = i;
    }
    
    for(int i=0; i<m; i++){ 
        cin >> edge[i].s >> edge[i].e >> edge[i].w;
    }    

    sort(edge.begin(), edge.begin() + m, compareEdges);
    for(const auto& eg : edge){
        int s = find(eg.s);
        int e = find(eg.e);
        if(s == e) continue;
        uni(s,e);
        c += eg.w;
    }
    cout<<c;
    
    return 0;   
}