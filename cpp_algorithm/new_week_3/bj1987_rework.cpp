#include <bits/stdc++.h>

using namespace std;

string s;
int R, C, ret_1 = INT_MIN, ret_2 = INT_MIN;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char board[20][20];
bool visited[26];

void back_tracking(int y, int x, int cnt) {
    ret_1 = max(ret_1, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;

        int idx = board[ny][nx] - 'A';
        if (!visited[idx]) {
            visited[idx] = true;
            back_tracking(ny, nx, cnt + 1);
            visited[idx] = false;
        }
    }
}

void bit_masking(int y, int x, int cnt, int state) {
    ret_2 = max(ret_2, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;

        int idx = board[ny][nx] - 'A';
        if (!(state & (1 << idx))) {
            bit_masking(ny, nx, cnt + 1, (state | (1 << idx)));
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) board[i][j] = s[j];
    }

    int idx = board[0][0] - 'A';
    visited[idx] = true;
    back_tracking(0, 0, 1);
    bit_masking(0, 0, 1, (1 << idx));

    cout << ret_1 << "\n" << ret_2;
}