#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n < ny || nx < 0 || m < nx) continue;
        if (!adj[ny][nx] || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> adj[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (adj[i][j] && !visited[i][j]) {
                cnt++;
                go(i, j);
            }
        }
    }

    cout << cnt;
}