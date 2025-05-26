#include <bits/stdc++.h>

using namespace std;

string s;
int r, c, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int board[1000][1000];
vector<vector<int>> man_visited(1000, vector<int>(1000, 0));
vector<vector<int>> fire_visited(1000, vector<int>(1000, INT_MAX));
queue<pair<int, int>> points;
pair<int, int> man;

void go_fire() {
    while (points.size()) {
        int cy, cx;
        tie(cy, cx) = points.front();
        points.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (board[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] != INT_MAX) continue;
            fire_visited[ny][nx] = fire_visited[cy][cx] + 1;
            points.push({ny, nx});
        }
    }
}

void go_man() {
    man_visited[man.first][man.second] = 1;
    points.push(man);

    while (points.size()) {
        int cy, cx;
        tie(cy, cx) = points.front();
        points.pop();

        if (cy == r - 1 || cx == c - 1 || cy == 0 || cx == 0) {
            ret = man_visited[cy][cx];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (board[ny][nx] == '#') continue;
            if (man_visited[ny][nx]) continue;
            if (fire_visited[ny][nx] <= man_visited[cy][cx] + 1) continue;
            man_visited[ny][nx] = man_visited[cy][cx] + 1;
            points.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'J') man = {i, j};
            if (board[i][j] == 'F') {
                points.push({i, j});
                fire_visited[i][j] = 1;
            }
        }
    }

    go_fire();
    go_man();

    cout << (ret ? to_string(ret) : "IMPOSSIBLE");
}