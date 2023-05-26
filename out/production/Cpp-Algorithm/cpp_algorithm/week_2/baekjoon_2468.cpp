#include <bits/stdc++.h>

using namespace std;

int n;
int adj[104][104], visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
set<int> range;

void dfs(int y, int x, int height) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (adj[ny][nx] < height) continue;
        if (!visited[ny][nx]) dfs(ny, nx, height);
    }
}

int main() {
    // 지역의 행렬 길이
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> adj[y][x];
            range.insert(adj[y][x]);
        }
    }

    vector<int> result;
    for (int height : range) {
        int cnt = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (adj[y][x] >= height && !visited[y][x]) {
                    cnt++;
                    dfs(y, x, height);
                }
            }
        }
        result.push_back(cnt);
        memset(visited, 0, sizeof(visited));
    }

    cout << *max_element(result.begin(), result.end());
}