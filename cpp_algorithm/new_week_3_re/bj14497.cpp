#include <bits/stdc++.h>

using namespace std;

string s;
int n, m, sx, sy, ex, ey, cnt, flag = 0;
char board[301][301];
int visited[301][301];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void move(int x, int y) {
    visited[x][y] = 1;

    if (board[x][y] == '#') {
        flag = 1;
        return;
    }

    if (board[x][y] == '1') {
        board[x][y] = '0';
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || n < nx || ny <= 0 || m < ny) continue;
        if (visited[nx][ny]) continue;
        move(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> sx >> sy >> ex >> ey;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) board[i][j] = s[j - 1];
    }

    while (!flag) {
        memset(visited, 0, sizeof(visited));
        move(sx, sy);
        cnt++;
    }

    cout << cnt;
}