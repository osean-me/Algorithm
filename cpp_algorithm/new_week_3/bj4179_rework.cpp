#include <bits/stdc++.h>

using namespace std;

int r, c, cy, cx, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char adj[1001][1001];
pair<int, int> point;
queue<pair<int, int>> q;
vector<vector<int>> fires(1001, vector<int>(1001, INT_MAX)),
    visited(1001, vector<int>(1001, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 'J') point = {i, j};
            if (adj[i][j] == 'F') {
                fires[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (adj[ny][nx] == '#' || fires[ny][nx] != INT_MAX) continue;
            fires[ny][nx] = fires[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    visited[point.first][point.second] = 1;
    q.push(point);
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        if (cy == 0 || cy == r - 1 || cx == 0 || cx == c - 1) {
            ret = visited[cy][cx];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (adj[ny][nx] == '#' || visited[ny][nx]) continue;
            if (fires[ny][nx] <= visited[cy][cx] + 1) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    cout << (ret ? to_string(ret) : "IMPOSSIBLE");
}