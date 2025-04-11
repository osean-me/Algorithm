#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, iy, ix, jy, jx, ret, flag;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<vector<char>> adj;
vector<vector<int>> visited;
queue<pair<int, int>> q;

void go(int y, int x) {
    visited[y][x] = 1;

    if (adj[y][x] == '#') {
        flag = 1;
        return;
    }

    if (adj[y][x] == '1') {
        adj[y][x] = '0';
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> iy >> ix;
    cin >> jy >> jx;

    adj.resize(n + 1, vector<char>(m + 1, '0'));
    visited.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) adj[i][j] = s[j];
    }

    while (!flag) {
        go(iy - 1, ix - 1);
        visited.assign(n + 1, vector<int>(m + 1, 0));
        ret++;
    }

    cout << ret;
}