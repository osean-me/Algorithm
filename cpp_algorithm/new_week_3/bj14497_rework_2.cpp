#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, sy, sx, fy, fx, flag, cnt;
char adj[301][301];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}, visited[301][301];
queue<pair<int, int>> q;

void go() {
    memset(visited, 0, sizeof(visited));
    visited[sy - 1][sx - 1] = 1;
    q.push({sy - 1, sx - 1});

    while (q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();

        if (cy == (fy - 1) && cx == (fx - 1)) {
            flag = 1;
            return;
        }

        if (adj[cy][cx] == '1') {
            adj[cy][cx] = '0';
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> n >> m >> sy >> sx >> fy >> fx;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) adj[i][j] = s[j];
    }

    while (!flag) {
        go();
        cnt++;
    }

    cout << cnt;
}