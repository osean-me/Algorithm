#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void go(int y, int x) {
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
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for (int j = 1; j <= m; j++) adj[i][j] = input[j - 1] - '0';
    }

    go(1, 1);

    cout << visited[n][m];
}