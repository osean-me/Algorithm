#include <bits/stdc++.h>

using namespace std;

int n, m, t_cnt = 0, cnt = 0;
int adj[10][10] = {}, visited[10][10] = {};
vector<pair<int, int>> empty_areas;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x]++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (!adj[ny][nx] && !visited[ny][nx]) {
            adj[ny][nx] = 3;
            dfs(ny, nx);
        }
    }
}

int go() {
    cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 2 && !visited[i][j]) dfs(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!adj[i][j]) cnt++;
            if (adj[i][j] == 3) adj[i][j] = 0;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (!adj[i][j]) empty_areas.push_back({i, j});
        }
    }

    for (int i = 0; i < empty_areas.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int l = 0; l < j; l++) {
                adj[empty_areas[i].first][empty_areas[i].second] = 1;
                adj[empty_areas[j].first][empty_areas[j].second] = 1;
                adj[empty_areas[l].first][empty_areas[l].second] = 1;
                t_cnt = max(t_cnt, go());
                adj[empty_areas[i].first][empty_areas[i].second] = 0;
                adj[empty_areas[j].first][empty_areas[j].second] = 0;
                adj[empty_areas[l].first][empty_areas[l].second] = 0;
            }
        }
    }

    cout << t_cnt;
}