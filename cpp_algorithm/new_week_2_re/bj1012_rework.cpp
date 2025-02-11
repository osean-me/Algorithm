#include <bits/stdc++.h>

using namespace std;

int tc, n, m, cn, cm, tpc, cnt;
int adj[51][51], visited[51][51];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> rst;

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
    cout.tie(NULL);

    cin >> tc;

    for (int t = 0; t < tc; t++) {
        cin >> m >> n >> tpc;

        for (int p = 0; p < tpc; p++) {
            cin >> cm >> cn;
            adj[cn][cm] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] && !visited[i][j]) {
                    go(i, j);
                    cnt++;
                }
            }
        }

        rst.push_back(cnt);
        cnt = 0;
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
    }

    for (int r : rst) cout << r << "\n";
}