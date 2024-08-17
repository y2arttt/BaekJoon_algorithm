#include <iostream>
#include <queue>
#include <cstring> 

using namespace std;

int map[100][100];
int air[100][100];
int n, m;
queue<pair<int, int>> idx;
bool visited[100][100];
int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void airCheck() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true; 
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (auto& move : moves) {
            int ni = i + move[0];
            int nj = j + move[1];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (map[ni][nj] == 1) {
                air[ni][nj]++;
            } else if (!visited[ni][nj]) {
                visited[ni][nj] = true; 
                q.push({ni, nj});
            }
        }
    }
}

bool cheese() {
    bool melted = false;
    int size = idx.size();
    for (int k = 0; k < size; k++) {
        int i = idx.front().first;
        int j = idx.front().second;
        idx.pop();

        if (air[i][j] >= 2) {
            map[i][j] = 0;
            melted = true;
        } else {
            idx.push({i, j});
        }
    }

    return melted;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
	int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            cin >> map[i][j];
            if (map[i][j] == 1) {
                idx.push({i, j});
            }
        }
    }

    while (!idx.empty()) {
        memset(air, 0, sizeof(air));
        memset(visited, false, sizeof(visited));

        airCheck();

        if (!cheese()) break; 
        cnt++; 
    }

    cout << cnt;

    return 0;
}
