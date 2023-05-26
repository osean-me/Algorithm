#include <bits/stdc++.h>
using namespace std;

int t = 0, n = 0, m = 0, k = 0, y = 0, x = 0, cnt = 0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int adj[50][50] = {}, visited[50][50] = {};

void dfs(int cy, int cx) {
    visited[cy][cx] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (adj[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    cin >> t;
    vector<int> ret = vector<int>();
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        for (int j = 0; j < k; j++) {
            cin >> y >> x;
            if (y < n && x < m) adj[y][x] = 1;
        }

        for (int yy = 0; yy < n; yy++) {
            for (int xx = 0; xx < m; xx++) {
                if (adj[yy][xx] && !visited[yy][xx]) {
                    cnt++;
                    dfs(yy, xx);
                }
            }
        }
        ret.push_back(cnt);
        n = 0, m = 0, k = 0, y = 0, x = 0, cnt = 0;
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
    }

    for (int result : ret) cout << result << '\n';
}