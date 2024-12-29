#include <bits/stdc++.h>

using namespace std;

int n, y, x, cnt;
int adj[51][51] = {}, visited[51][51] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> ret;

void go(int sy, int sx) {
    visited[sy][sx] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if (ny < 0 || y < ny || nx < 0 || x < nx) continue;
        if (!adj[ny][nx] || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int total = 0;
        cin >> y >> x >> cnt;
        for (int j = 0; j < cnt; j++) {
            int cy, cx;
            cin >> cy >> cx;
            adj[cy][cx] = 1;
        }

        for (int sy = 0; sy < y; sy++) {
            for (int sx = 0; sx < x; sx++) {
                if (adj[sy][sx] && !visited[sy][sx]) {
                    total++;
                    go(sy, sx);
                }
            }
        }
        ret.push_back(total);
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
    }

    for (int result : ret) cout << result << "\n";
}