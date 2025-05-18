#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int visited[50][50];
char board[50][50];
queue<pair<int, int>> points;

void go(int x, int y) {
    visited[x][y] = 1;
    points.push({x, y});

    while (points.size()) {
        int cx, cy;
        tie(cx, cy) = points.front();
        points.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if (board[nx][ny] == 'W' || visited[nx][ny]) continue;

            visited[nx][ny] = visited[cx][cy] + 1;
            ret = max(ret, visited[nx][ny]);
            points.push({nx, ny});
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

    cout << (ret - 1);
}