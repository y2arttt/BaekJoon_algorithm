#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int graph[9][9];
int maxc;

int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void bfs() {
    int tmpGraph[9][9];
    int cnt = 0;
    memcpy(tmpGraph, graph, 9 * 9 * sizeof(int));
    queue<pair<int,int>> pq;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmpGraph[i][j] == 2 ) pq.push({i,j});
        }
    }
    while (!pq.empty())
    {
        int i = pq.front().first;
        int j = pq.front().second;
        pq.pop();
        for(int k=0;k<4; k++){
            int nextI = i+moves[k][0];
            int nextJ = j+moves[k][1];
            if( nextI < 0 || nextI >= n ||  nextJ < 0 || nextJ >=m) continue;
            if(tmpGraph[nextI][nextJ] == 0){
                tmpGraph[nextI][nextJ] = 2;
                pq.push({nextI,nextJ});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmpGraph[i][j] == 0) cnt++;
        }
    }
    maxc = max(maxc,cnt);
}

void walls(int cnt) {
    if(cnt == 3) {
        bfs(); 
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(graph[i][j] == 0) {
                graph[i][j] = 1;
                walls(cnt + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    maxc = 0;
    walls(0);
    cout << maxc;

    return 0;
}