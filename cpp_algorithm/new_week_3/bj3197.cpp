#include <bits/stdc++.h>

using namespace std;

string s;
int r, c, flag, cnt;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int visited[1501][1501], c_visited[1501][1501];
char adj[1501][1501];
vector<pair<int, int>> points;
queue<pair<int, int>> q, c_q;

void go(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});

    while (q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();

        if (adj[cy][cx] == 'L') continue;

        if (adj[cy][cx] == 'X') {
            visited[cy][cx] = 1;
            adj[cy][cx] = '.';
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

void check() {
    int sy, sx, fy, fx;
    tie(sy, sx) = points[0];
    tie(fy, fx) = points[1];

    c_visited[sy][sx] = 1;
    c_q.push({sy, sx});

    while (c_q.size()) {
        int cy, cx;
        tie(cy, cx) = c_q.front();
        c_q.pop();

        if (cy == fy && cx == fx) {
            flag = 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (!c_visited[ny][nx] && adj[ny][nx] != 'X') {
                c_visited[ny][nx] = 1;
                c_q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            adj[i][j] = s[j];
            if (adj[i][j] == 'L') points.push_back({i, j});
        }
    }
    while (!flag) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (adj[i][j] == '.' && !visited[i][j]) go(i, j);
            }
        }
        memset(visited, 0, sizeof(visited));
        check();
        memset(c_visited, 0, sizeof(c_visited));
        cnt++;
    }

    cout << cnt;
}