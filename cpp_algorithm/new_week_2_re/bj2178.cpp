#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (!q.empty()) {
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
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) adj[i][j] = s[j] - '0';
    }

    go(0, 0);
    cout << visited[n - 1][m - 1];
}