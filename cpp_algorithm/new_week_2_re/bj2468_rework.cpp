#include <bits/stdc++.h>

using namespace std;

int n, cnt, m_cnt;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void go(int y, int x, int h) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n < ny || nx < 0 || n < nx) continue;
        if (adj[ny][nx] < h || visited[ny][nx]) continue;
        go(ny, nx, h);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> adj[i][j];
    }

    for (int h = 0; h <= 100; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (h <= adj[i][j] && !visited[i][j]) {
                    go(i, j, h);
                    cnt++;
                }
            }
        }
        m_cnt = max(m_cnt, cnt);
        cnt = 0;
        memset(visited, 0, sizeof(visited));
    }

    cout << m_cnt;
}