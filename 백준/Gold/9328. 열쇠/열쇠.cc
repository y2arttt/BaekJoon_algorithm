#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> start;
        char map[100][100];

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (map[i][j] != '*') start.push_back({i, j});
                }
            }
        }

        string key;
        cin >> key;
        if(key[0] =='0') key = "";
        int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        bool check[100][100] = {false};

        queue<pair<int, int>> q;
        for (auto& s : start) {
            q.push({s.first, s.second});
            check[s.first][s.second] = true;
        }

        int cnt = 0;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            char current = map[i][j];

            if (current == '$') {
                cnt++;
                map[i][j] = '.'; 
            }

            if ('A' <= current && current <= 'Z') {
                if (key.find(tolower(current)) != string::npos) { 
                    map[i][j] = '.';  
                } else {
                    continue;  
                }
            }

            if ('a' <= current && current <= 'z') {
                if (key.find(current) == string::npos) {
                    key += current;  
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) check[i][j] = false; 
                    }
                   
                    while (!q.empty()) q.pop();
                   
                    for (auto& s : start) {
                        q.push({s.first, s.second});
                        check[s.first][s.second] = true;
                    }
                    continue;
                }
            }

            for (auto& mv : move) {
                int mi = i + mv[0];
                int mj = j + mv[1];
                if (mi < 0 || mi >= n || mj < 0 || mj >= m) continue;
                if (map[mi][mj] != '*' && !check[mi][mj]) {
                    q.push({mi, mj});
                    check[mi][mj] = true;
                }
            }
        }

        cout << cnt << '\n'; 
    }

    return 0;
}