#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
string board[10];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct pos {
    int i, j;
    pos(int i, int j) : i(i), j(j) {}
};

struct state { 
    pos red, blue;
    int cnt;
    state(pos r, pos b, int c) : red(r), blue(b), cnt(c) {}
};

int move(pos& current, int di, int dj) {
    int distance = 0;
    while (true) {
        int ni = current.i + di;
        int nj = current.j + dj;
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || board[ni][nj] == '#') break;
        current = {ni, nj};
        distance++;
        if (board[ni][nj] == 'O') return -1;  // 구멍에 빠진 경우
    }
    return distance;
}

int main() {
    cin >> n >> m;
    
    pos r(-1, -1), b(-1, -1);

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') r = {i, j};
            if (board[i][j] == 'B') b = {i, j};
        }
    }

    queue<state> q;
    bool visited[10][10][10][10] = {false};

    q.push({r, b, 0});
    visited[r.i][r.j][b.i][b.j] = true;

    while (!q.empty()) {
        state current = q.front();
        q.pop();

        if (current.cnt >= 10) break;

        for (auto& d : dir) {
            pos newRed = current.red;
            pos newBlue = current.blue;
            int dr = move(newRed, d[0], d[1]);
            int db = move(newBlue, d[0], d[1]);

            if (db == -1) continue;  // 파란 구슬이 구멍에 빠진 경우
            if (dr == -1) {  // 빨간 구슬이 구멍에 빠진 경우
                cout << current.cnt + 1 << endl;
                return 0;
            }

            if (newRed.i == newBlue.i && newRed.j == newBlue.j) {
                if (dr > db) {
                    newRed.i -= d[0];
                    newRed.j -= d[1];
                } else {
                    newBlue.i -= d[0];
                    newBlue.j -= d[1];
                }
            }

            if (visited[newRed.i][newRed.j][newBlue.i][newBlue.j]) continue;

            visited[newRed.i][newRed.j][newBlue.i][newBlue.j] = true;
            q.push({newRed, newBlue, current.cnt + 1});
        }
    }

    cout << -1 << endl;
    return 0;
}