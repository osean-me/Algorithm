#include <bits/stdc++.h>

using namespace std;

int n, m, k, cnt;
int sx, sy, ex, ey;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> size_list;

int go(int y, int x, int c) {
    visited[y][x] = 1;
    c++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || m <= ny || nx < 0 || n <= nx) continue;
        if (adj[ny][nx] || visited[ny][nx]) continue;
        c += go(ny, nx, 0);
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> sx >> sy >> ex >> ey;
        for (int y = sy; y < ey; y++) {
            for (int x = sx; x < ex; x++) adj[y][x]++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!adj[i][j] && !visited[i][j]) {
                int s = go(i, j, 0);
                size_list.push_back(s);
                cnt++;
            }
        }
    }

    sort(size_list.begin(), size_list.end());
    cout << cnt << "\n";
    for (int s : size_list) cout << s << " ";
}