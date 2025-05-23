#include <bits/stdc++.h>

using namespace std;

string s;
int r, c;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char board[1000][1000];
int man_visited[1000][1000], fire_visited[1000][1000];
queue<pair<int, int>> man_points, fire_points;
pair<int, int> man;

void go_fire() {
    while (fire_points.size()) {
        int cy, cx;
        tie(cy, cx) = fire_points.front();
        fire_points.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (fire_visited[ny][nx]) continue;
            if (board[ny][nx] == '#') continue;

            fire_visited[ny][nx] = fire_visited[cy][cx] + 1;
            fire_points.push({ny, nx});
        }
    }
}

int go_man() {
    man_visited[man.first][man.second] = 1;
    man_points.push(man);

    while (man_points.size()) {
        int cy, cx;
        tie(cy, cx) = man_points.front();
        man_points.pop();

        // 탈출 조건
        if (cy == 0 || cy == r - 1 || cx == 0 || cx == c - 1) {
            return man_visited[cy][cx];
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (man_visited[ny][nx]) continue;
            if (board[ny][nx] == '#') continue;
            if (fire_visited[ny][nx] &&
                fire_visited[ny][nx] <= man_visited[cy][cx])
                continue;

            man_visited[ny][nx] = man_visited[cy][cx] + 1;
            man_points.push({ny, nx});
        }
    }

    return -1;
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
                fire_points.push({i, j});
                fire_visited[i][j] = 1;
            }
        }
    }

    if (man.first == 0 || man.first == r - 1 || man.second == 0 ||
        man.second == c - 1) {
        cout << 1;
    }

    go_fire();
    int ret = go_man();

    cout << (ret == -1 ? "IMPOSSIBLE" : to_string(ret));
}