#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int visited[50][50];
char board[50][50];
queue<pair<int, int>> points;

void go(int y, int x) {
    visited[y][x] = 1;
    points.push({y, x});

    while (points.size()) {
        int cy, cx;
        tie(cy, cx) = points.front();
        points.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if (visited[ny][nx] || board[ny][nx] == 'W') continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            ret = max(ret, visited[ny][nx]);
            points.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) board[i][j] = s[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'L') {
                memset(visited, 0, sizeof(visited));
                go(i, j);
            }
        }
    }

    cout << ret - 1;
}