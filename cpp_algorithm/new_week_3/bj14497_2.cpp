#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, iy, ix, jy, jx, ret, flag;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char adj[301][301];
int visited[301][301];
queue<pair<int, int>> q;

void go(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});

    while (q.size()) {
        int cy, cx;
        tie(cy, cx) = q.front();
        q.pop();

        if (adj[cy][cx] == '#') {
            flag = 1;
            return;
        }

        if (adj[cy][cx] == '1') {
            adj[cy][cx] = '0';
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> iy >> ix >> jy >> jx;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) adj[i][j] = s[j];
    }

    while (!flag) {
        go(iy - 1, ix - 1);
        memset(visited, 0, sizeof(visited));
        ret++;
    }

    cout << ret;
}