#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int graph[1001][1001];
int visited[1001][1001][2];

struct Node {
    int x, y, w;
};

int moves[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int bfs() {
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        
        int x = node.x;
        int y = node.y;
        int w = node.w;//벽뿌수면 1

        if (x == n - 1 && y == m - 1) {
            return visited[x][y][w];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + moves[i][0];
            int ny = y + moves[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (graph[nx][ny] == 0 && visited[nx][ny][w] == 0) {
                    visited[nx][ny][w] = visited[x][y][w] + 1;
                    q.push({nx, ny, w});
                }
                else if (graph[nx][ny] == 1 && w == 0 && visited[nx][ny][1] == 0) {
                    visited[nx][ny][1] = visited[x][y][w] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            graph[i][j] = row[j] - '0';
        }
    }

    memset(visited, 0, sizeof(visited));

    cout << bfs() << endl;

    return 0;
}
