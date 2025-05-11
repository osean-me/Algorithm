#include <bits/stdc++.h>

using namespace std;

int r, c, k, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int visited[5][5];
char board[5][5];

void go(int y, int x, int cnt) {
    if (y == c - 1 && x == 0) {
        if (cnt == k) ret++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || c <= ny || nx < 0 || r <= nx) continue;
        if (visited[ny][nx] || board[ny][nx] == 'T') continue;

        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> board[i][j];
    }

    visited[0][r - 1] = 1;
    go(0, r - 1, 1);

    cout << ret;
}