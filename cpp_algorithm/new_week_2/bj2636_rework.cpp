#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<vector<pair<int, int>>> points;

void dfs(int y, int x) {
    visited[y][x]++;

    if (adj[y][x] == 1) {
        points[points.size() - 1].push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx || visited[ny][nx]) continue;
        dfs(ny, nx);
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
        points.push_back(vector<pair<int, int>>());

        dfs(0, 0);

        int last_index = points.size() - 1;

        for (pair<int, int> p : points[last_index]) adj[p.first][p.second] = 0;

        memset(visited, 0, sizeof(visited));

        if (!points[last_index].size()) {
            cout << last_index << "\n" << points[points.size() - 2].size();
            break;
        }
    }
}