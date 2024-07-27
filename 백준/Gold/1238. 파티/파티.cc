#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;

vector<pair<int, int>> edge[100001];
bool visited[100001];
int maxs;
int farthest_node;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,X;
    cin >> N>>M>>X;
    int dist[N+1];
    int maxx=0;
    vector <pair<int,int>> city[N+1];
    for(int i=0; i<M; i++){
        int a,b,w;
        cin>>a>>b>>w;
        city[a].push_back({w,b});
    }
    int start = 1;
    priority_queue <pair<int,int>> pq;
    while (start <= N)
    {
        if(start == X) {
            start++;
            continue;
        }
        fill(dist, dist + N + 1, INF);
        pq.push({0,start});
        while (!pq.empty())
        {
            int current = pq.top().second;
            int weight = - pq.top().first;
            pq.pop();
            for(auto& c:city[current]){
                int next = c.second;
                int nextWeight = weight + c.first;
                if(dist[next] > nextWeight ){
                    dist[next] = nextWeight;
                    pq.push({-nextWeight,next});
                }
            }
        }
        int tmp=dist[X];
        fill(dist, dist + N + 1, INF);
        pq.push({0,X});
        while (!pq.empty())
        {
            int current = pq.top().second;
            int weight = - pq.top().first;
            pq.pop();
            for(auto& c:city[current]){
                int next = c.second;
                int nextWeight = weight + c.first;
                if(dist[next] > nextWeight ){
                    dist[next] = nextWeight;
                    pq.push({-nextWeight,next});
                }
            }
        }
        maxx = max(maxx,tmp+dist[start]);

        start++;
        
    }
    cout<<maxx;

    return 0;
}