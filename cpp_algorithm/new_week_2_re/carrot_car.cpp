#include <bits/stdc++.h>

using namespace std;

int n, m;
int sn, sm;
int fn, fm;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void go() {
    queue<pair<int, int>> q;
    q.push({sn, sm});
    visited[sn][sm] = 1;
    while (!q.empty()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n < ny || nx < 0 || m < nx) continue;
            if (visited[ny][nx] || !adj[ny][nx]) continue;
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
    cin >> sn >> sm;
    cin >> fn >> fm;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> adj[i][j];
    }

    go();

    cout << visited[fn][fm];
}