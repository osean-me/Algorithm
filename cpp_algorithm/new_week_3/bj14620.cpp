#include <bits/stdc++.h>

using namespace std;

int n, fee = INT_MAX;
int board[10][10], visited[10][10];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

bool validate(int y, int x) {
    if (visited[y][x]) return false;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 화단 밖으로 나가는 경우
        if (ny < 0 || n <= ny || nx < 0 || n <= nx || visited[ny][nx]) {
            return false;
        }
    }

    return true;
}

int go(int y, int x) {
    int sum = board[y][x];
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += board[ny][nx];
    }

    return sum;
}

void back(int y, int x) {
    visited[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (!validate(i, j)) continue;
            int a = go(i, j);

            for (int k = 1; k < n - 1; k++) {
                for (int l = 1; l < n - 1; l++) {
                    if (!validate(k, l)) continue;
                    int b = go(k, l);

                    for (int p = 1; p < n - 1; p++) {
                        for (int q = 1; q < n - 1; q++) {
                            if (!validate(p, q)) continue;
                            int c = go(p, q);
                            fee = min(fee, a + b + c);
                            back(p, q);
                        }
                    }

                    back(k, l);
                }
            }

            back(i, j);
        }
    }

    cout << fee;
}