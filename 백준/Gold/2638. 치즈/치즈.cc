#include <iostream>
#include <queue>
#include <cstring> 

using namespace std;

int map[100][100];
int air[100][100];
int n, m;
queue<pair<int, int>> idx;//
bool visited[100][100];
int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void airCheck() {
    queue<pair<int, int>> q;
	memset(air, 0, sizeof(air));
	memset(visited, false, sizeof(visited));
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



int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
	int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            cin >> map[i][j];

        }
    }
    while (true) {
		bool change = false;
        airCheck();
		for (int i=0; i<n; i++) {
			for(int j=0; j<m; j++){
				if (air[i][j] >= 2) {
					map[i][j] = 0;
					change= true;
				}
			}
		}
        cnt++; 
		if(!change)break;
    }

    cout << cnt-1;

    return 0;
}
