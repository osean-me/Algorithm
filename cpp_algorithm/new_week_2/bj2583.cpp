#include <bits/stdc++.h>

using namespace std;

int m, n, k, cnt = 0, total = 0;
int adj[101][101] = {}, visited[101][101] = {}, vertices[2][2];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> areas;

void fill() {
    for (int i = vertices[0][0]; i < vertices[1][0]; i++) {
        for (int j = vertices[0][1]; j < vertices[1][1]; j++) adj[i][j]++;
    }
}

void go(int y, int x) {
    cnt++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (adj[ny][nx] || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> vertices[0][0] >> vertices[0][1];
        cin >> vertices[1][0] >> vertices[1][1];
        fill();
        memset(vertices, 0, sizeof(vertices));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!adj[i][j] && !visited[i][j]) {
                total++;
                go(i, j);
                areas.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(areas.begin(), areas.end());
    cout << total << "\n";
    for (int area : areas) cout << area << " ";
}