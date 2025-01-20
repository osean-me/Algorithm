#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void go(int y, int x) {
    visited[y][x] = 1;
    if (adj[y][x] == 1) {
        v.push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> adj[i][j];
    }

    while (true) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j]) flag = true;
            }
        }
        if (!flag) {
            cout << cnt << "\n" << v.size();
            break;
        }
        memset(visited, 0, sizeof(visited));
        v.clear();
        go(0, 0);
        cnt++;
        for (pair<int, int> p : v) adj[p.first][p.second] = 0;
    }
}