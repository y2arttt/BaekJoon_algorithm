#include <iostream>
#include <algorithm>
using namespace std;

int n,m;   
int map[500][500];
int dp[500][500];

int dfs(int i, int j){
    int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    if (i == n-1 && j == m-1) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    for(auto& mv : move){
        int ni=i+mv[0], mj=j+mv[1];
        if(0<=ni && ni<n && 0 <= mj && mj < m){
            if(map[i][j] > map[ni][mj]){
                dp[i][j]+=dfs(ni,mj);
            }
        }
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m; 

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    
    cout<<dfs(0,0);;
    return 0;
}
