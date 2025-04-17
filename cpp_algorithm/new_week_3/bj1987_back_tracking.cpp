#include <bits/stdc++.h>

using namespace std;

string row;
int r, c, ret = INT_MIN;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}, alphabets[26];
char board[20][20];

void go(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
        int alphabet = board[ny][nx] - 'A';
        if (!alphabets[alphabet]) {
            alphabets[alphabet] = true;
            go(ny, nx, cnt + 1);
            alphabets[alphabet] = false;
        }
    }
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> row;
        for (int j = 0; j < c; j++) board[i][j] = row[j];
    }

    int alphabet = board[0][0] - 'A';
    alphabets[alphabet] = true;
    go(0, 0, 1);

    cout << ret << endl;
}