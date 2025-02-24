#include <bits/stdc++.h>

using namespace std;

int n, m, tcnt;
int adj[9][9], visited[9][9];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> empty_places;

void outbreak(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (!adj[ny][nx] && !visited[ny][nx]) {
            adj[ny][nx] = 4;
            outbreak(ny, nx);
        }
    }
}

int go() {
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 2 && !visited[i][j]) outbreak(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!adj[i][j]) cnt++;
            if (adj[i][j] == 4) adj[i][j] = 0;
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
            if (!adj[i][j]) empty_places.push_back({i, j});
        }
    }

    for (int a = 0; a < empty_places.size(); a++) {
        for (int b = 0; b < a; b++) {
            for (int c = 0; c < b; c++) {
                adj[empty_places[a].first][empty_places[a].second] = 3;
                adj[empty_places[b].first][empty_places[b].second] = 3;
                adj[empty_places[c].first][empty_places[c].second] = 3;
                tcnt = max(tcnt, go());
                adj[empty_places[a].first][empty_places[a].second] = 0;
                adj[empty_places[b].first][empty_places[b].second] = 0;
                adj[empty_places[c].first][empty_places[c].second] = 0;
            }
        }
    }

    cout << tcnt;
}