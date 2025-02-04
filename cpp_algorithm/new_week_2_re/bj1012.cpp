#include <bits/stdc++.h>

using namespace std;

int n, y, x, t, ty, tx, cnt;
int adj[51][51], visited[51][51];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> answer;

void go(int cy, int cx) {
    visited[cy][cx]++;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || y < ny || nx < 0 || x < nx) continue;
        if (!adj[ny][nx] || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> t;
        for (int j = 0; j < t; j++) {
            cin >> tx >> ty;
            adj[ty][tx] = 1;
        }

        for (int cy = 0; cy < y; cy++) {
            for (int cx = 0; cx < x; cx++) {
                if (adj[cy][cx] && !visited[cy][cx]) {
                    go(cy, cx);
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }

    for (int tcnt : answer) cout << tcnt << "\n";
}