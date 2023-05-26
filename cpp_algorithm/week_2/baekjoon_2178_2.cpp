#include <bits/stdc++.h>
using namespace std;

int const V = 104;
int y = 0, x = 0, n = 0, m = 0;
int adj[V][V] = {}, visited[V][V] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx) {
    queue<pair<int, int> > q = queue<pair<int, int> >();
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!adj[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        string input = "";
        cin >> input;
        for (int x = 0; x < m; x++) {
            if (input[x] == '1') {
                adj[y][x] = 1;
            }
        }
    }

    bfs(0, 0);
    cout << visited[n - 1][m - 1] << '\n';
}