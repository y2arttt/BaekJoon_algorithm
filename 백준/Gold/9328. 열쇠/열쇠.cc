#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>  
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> start;
        char map[102][102];  
        bool check[102][102]; 
        memset(check, false, sizeof(check)); 
        memset(map, '.', sizeof(map));  
        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
            }
        }
        
        // 덧댄 면
        for (int i = 0; i <= n+1; i++) {
            start.push_back({i, 0});
            start.push_back({i, m+1});
        }
        for (int j = 1; j <= m; j++) {
            start.push_back({0, j});
            start.push_back({n+1, j});
        }

        // Key 설정
        string key;
        cin >> key;
        bool keyArr[26] = {false};
        if (key != "0") {
            for (char c : key) {
                keyArr[c - 'a'] = true;
            }
        }
        
        // BFS 
        int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        queue<pair<int, int>> door[26];
        
        for (auto& s : start) {
            q.push(s);
            check[s.first][s.second] = true;
        }

        int cnt = 0;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (auto& mv : move) {
                int mi = i + mv[0];
                int mj = j + mv[1];
                if (mi < 0 || mi > n+1 || mj < 0 || mj > m+1) continue;
                if (map[mi][mj] != '*' && !check[mi][mj]) {
                    char next = map[mi][mj];
                    if (next == '$') {
                        cnt++;
                    }
                    else if ('A' <= next && next <= 'Z') {
                        if (!keyArr[next - 'A']) { 
                            door[next - 'A'].push({mi, mj});
                            continue;  
                        }
                    }
                    else if ('a' <= next && next <= 'z') {
                        if (!keyArr[next - 'a']) {
                            keyArr[next - 'a'] = true;
                            while (!door[next - 'a'].empty()) {
                                q.push(door[next - 'a'].front());
                                door[next - 'a'].pop();
                            }
                        }
                    }

                    q.push({mi, mj});
                    check[mi][mj] = true;
                }
            }
        }

        cout << cnt << '\n'; 
    }

    return 0;
}