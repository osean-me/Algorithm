#include <bits/stdc++.h>

using namespace std;

string row;
int r, c, ret = INT_MIN;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char board[20][20];

void go(int y, int x, int cnt, int used) {
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
        int alpha = board[ny][nx] - 'A';
        if (!(used & (1 << alpha))) {
            go(ny, nx, cnt + 1, (used | (1 << alpha)));
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> row;
        for (int j = 0; j < c; j++) board[i][j] = row[j];
    }

    int alpha = board[0][0] - 'A';
    go(0, 0, 1, (1 << alpha));

    cout << ret << endl;
}