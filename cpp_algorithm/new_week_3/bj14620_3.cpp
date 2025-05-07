#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MAX;
int board[10][10], visited[10][10];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

bool validate(int y, int x) {
    if (visited[y][x]) return false;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx || visited[ny][nx]) {
            return false;
        }
    }

    return true;
}

int plant(int y, int x) {
    int sum = board[y][x];
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        sum += board[ny][nx];
        visited[ny][nx] = 1;
    }

    return sum;
}

void unplant(int y, int x) {
    visited[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void go(int depth, int sum) {
    if (depth == 3) {
        ret = min(ret, sum);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (validate(i, j)) {
                go(depth + 1, sum + plant(i, j));
                unplant(i, j);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    go(0, 0);
    cout << ret;
}