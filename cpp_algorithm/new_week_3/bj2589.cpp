#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
string s;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int adj[51][51], visited[51][51];
queue<pair<int, int>> q;

void go(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});

    while (q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n < ny || nx < 0 || m < nx) continue;
            if (!adj[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            ret = max(ret, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'L') adj[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] && !visited[i][j]) {
                go(i, j);
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << ret - 1;
}