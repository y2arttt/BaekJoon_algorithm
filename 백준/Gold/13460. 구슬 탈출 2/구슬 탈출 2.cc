#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int di[4] = {1, -1, 0, 0}; 
int dj[4] = {0, 0, 1, -1}; 

struct pos {
    int i, j;
    pos(int i, int j) : i(i), j(j) {}
};

struct state { 
    pos red, blue;
    int cnt;
    state(pos r, pos b, int c) : red(r), blue(b), cnt(c) {}
};

pos move(pos current, int dir, const vector<string>& board) {
    while (true) {
        int ni = current.i + di[dir];
        int nj = current.j + dj[dir];

        if (board[ni][nj] == '#') break;
        if (board[ni][nj] == 'O') return {ni, nj};
        current = {ni, nj};
    }
    return current;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    pos r(-1, -1), b(-1, -1);

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') r = {i, j};
            if (board[i][j] == 'B') b = {i, j};
        }
    }

    queue<state> q;
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m, false))));

    q.push({r, b, 0});
    visited[r.i][r.j][b.i][b.j] = true;

    while (!q.empty()) {
        state current = q.front();
        q.pop();

        if (current.cnt >= 10) break;

        for (int dir = 0; dir < 4; dir++) {
            pos newRed = move(current.red, dir, board);
            pos newBlue = move(current.blue, dir, board);

            if (board[newBlue.i][newBlue.j] == 'O') continue;

            if (board[newRed.i][newRed.j] == 'O') {
                cout << current.cnt + 1 << endl;
                return 0;
            }

            if (newRed.i == newBlue.i && newRed.j == newBlue.j) {
                if (dir == 0) (current.red.i > current.blue.i) ? newBlue.i-- : newRed.i--;
                else if (dir == 1) (current.red.i < current.blue.i) ? newBlue.i++ : newRed.i++;
                else if (dir == 2) (current.red.j > current.blue.j) ? newBlue.j-- : newRed.j--;
                else (current.red.j < current.blue.j) ? newBlue.j++ : newRed.j++;
            }

            if (visited[newRed.i][newRed.j][newBlue.i][newBlue.j]) continue;

            visited[newRed.i][newRed.j][newBlue.i][newBlue.j] = true;
            q.push({newRed, newBlue, current.cnt + 1});
        }
    }

    cout << -1 << endl;
    return 0;
}