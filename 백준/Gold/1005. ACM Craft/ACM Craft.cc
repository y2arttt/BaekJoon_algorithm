#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        int build[1001]; // 짓는데 소요 시간
        int result[1001];
        int in[1001] = {0,}; // 진입 차수
        vector<vector<int>> edge(1001, vector<int>());
        cin>>n>>k;
        for(int i=1; i<=n; i++){
            cin>>build[i];
            result[i] = build[i];
        }
        for(int i=1; i<=k; i++){
            int s, e;
            cin>>s>>e;
            edge[s].push_back(e);
            in[e] ++;
        }
        int w;
        cin >> w;
        
        queue <int> q;
        for(int i=1; i<=n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            for(auto& e : edge[s]){
                result[e] = max(result[e], result[s] + build[e]);
                if(--in[e] == 0){
                    q.push(e);
                }
                
            }
        }
        cout<<result[w]<<"\n";
        
    }
    



    return 0;
}