#include <bits/stdc++.h>

using namespace std;

int n, m, answer;
int adj[9][9], visited[9][9];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> emptyAreas;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (!adj[ny][nx] && !visited[ny][nx]) {
            adj[ny][nx] = 4;
            dfs(ny, nx);
        }
    }
}

int go() {
    int cnt = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 2 && !visited[i][j]) dfs(i, j);
        }
    }

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
            if (!adj[i][j]) emptyAreas.push_back({i, j});
        }
    }

    for (int a = 0; a < emptyAreas.size(); a++) {
        for (int b = 0; b < a; b++) {
            for (int c = 0; c < b; c++) {
                adj[emptyAreas[a].first][emptyAreas[a].second] = 3;
                adj[emptyAreas[b].first][emptyAreas[b].second] = 3;
                adj[emptyAreas[c].first][emptyAreas[c].second] = 3;
                answer = max(answer, go());
                adj[emptyAreas[a].first][emptyAreas[a].second] = 0;
                adj[emptyAreas[b].first][emptyAreas[b].second] = 0;
                adj[emptyAreas[c].first][emptyAreas[c].second] = 0;
            }
        }
    }

    cout << answer;
}