#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001

int main() {
    int n, k;
    vector<int> dist(MAX, -1);
    vector<int> cnt(MAX, 0);   
    queue<int> q;
    
    cin >> n >> k;
    
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if (x == k) break; 
        
        for (int nx : {x-1, x+1, x*2}) {
            if (nx < 0 || nx >= MAX) continue;
            
            if (dist[nx] == -1) { 
                dist[nx] = dist[x] + 1;
                cnt[nx] = cnt[x];
                q.push(nx);
            } 
            else if (dist[nx] == dist[x] + 1) { 
                cnt[nx] += cnt[x];
            }
        }
    }
    
    cout << dist[k] << '\n';  
    cout << cnt[k]; 
    
    return 0;
}