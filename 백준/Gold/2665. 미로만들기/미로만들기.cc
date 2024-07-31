#include <iostream>
#include <queue>
#include <string>
#include <cstring>


using namespace std;



int main() {
    int n;
    int maps[50][50];
    bool visited[50][50];
    memset(visited, false, sizeof(visited));
    priority_queue<pair<int,pair<int,int>>> pq;
    int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    cin>>n;
    
    for(int i=0; i<n; i++){
        string row;
        cin>>row;
        for(int j = 0; j < n; j++) {
            maps[i][j] = row[j] - '0'; 
        }
    }
    pq.push({0,{0,0}});
    visited[0][0] = true;
    while (! pq.empty())
    {
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        int cnt= -pq.top().first;
        if(i== n-1 && j == n-1){
            cout<<cnt;
            break;
        }
        pq.pop();
        for(int k=0; k<4; k++){
            int nextI = i+moves[k][0];
            int nextJ = j+moves[k][1];
            if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n  )continue;
            if(visited[nextI][nextJ] == false ){
                visited[nextI][nextJ] = true;
                if(maps[nextI][nextJ] == 1 )pq.push({-cnt,{nextI,nextJ}});
                else pq.push({-(cnt+1),{nextI,nextJ}});
                
            }
        }
    }
    
    
    return 0;
}