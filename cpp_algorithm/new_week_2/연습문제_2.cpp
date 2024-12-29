#include <bits/stdc++.h>

using namespace std;

int n, m, sy, sx, ey, ex;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void BFS(int y, int x) {
    queue<pair<int, int>> q = queue<pair<int, int>>();
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
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }

    BFS(sy, sx);

    cout << visited[ey][ex];
}