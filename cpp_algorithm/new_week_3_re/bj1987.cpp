#include <bits/stdc++.h>

using namespace std;

string s;
int r, c, ret;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char board[20][20];
bool alphabets[36];

void solution(int x, int y, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;

        int adx = board[nx][ny] - 'A';
        if (!alphabets[adx]) {
            alphabets[adx] = true;
            solution(nx, ny, cnt + 1);
            alphabets[adx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) board[i][j] = s[j];
    }

    int adx = board[0][0] - 'A';
    alphabets[adx] = true;
    solution(0, 0, 1);
    cout << ret;
}