#include <bits/stdc++.h>

using namespace std;

int n, l, r, cnt;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int board[50][50], visited[50][50];
queue<pair<int, int>> points;

bool validate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) return true;
        }
    }
    return false;
}

void check(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        if (visited[ny][nx]) continue;

        int ret = board[y][x] - board[ny][nx];
        if (ret < 0) ret *= -1;
        if (ret < l || r < ret) continue;

        visited[ny][nx] = 1;
        check(ny, nx);
    }
}

void move() {
    int c = 0;
    int ret = 0;
    visited[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) continue;
            c++;
            ret += board[i][j];
        }
    }

    ret = (ret / c);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) continue;
            board[i][j] = ret;
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    while (true) {
        check(0, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << visited[i][j] << " ";
            cout << "\n";
        }
        cout << '\n';

        if (!validate()) {
            break;
        }

        move();
        memset(visited, 0, sizeof(visited));
        cnt++;
    }

    cout << cnt;
}