#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
int adj[101][101] = {}, visited[101][101] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
set<int> heights;
vector<int> result;

void go(int y, int x, int h) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n < ny || nx < 0 || n < nx) continue;
        if (adj[ny][nx] < h || visited[ny][nx]) continue;
        go(ny, nx, h);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            heights.insert(adj[i][j]);
        }
    }

    for (int h : heights) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (h <= adj[i][j] && !visited[i][j]) {
                    cnt++;
                    go(i, j, h);
                }
            }
        }
        result.push_back(cnt);
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }

    cout << *max_element(result.begin(), result.end());
}