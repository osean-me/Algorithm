#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int adj[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x, int c) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (!adj[ny][nx] && !visited[ny][nx]) {
            c = dfs(ny, nx, ++c);
        }
    }
    return c;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int corner[4];
        for (int j = 0; j < 4; j++) cin >> corner[j];

        for (int y = corner[1]; y < corner[3]; y++) {
            for (int x = corner[0]; x < corner[2]; x++) {
                adj[y][x] = 1;
            }
        }
    }
    int cnt = 0;
    vector<int> areas;
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (!adj[y][x] && !visited[y][x]) {
                cnt++;
                areas.push_back(dfs(y, x, 1));
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << cnt << '\n';
    for (int area : areas) {
        cout << area << " ";
    }
}