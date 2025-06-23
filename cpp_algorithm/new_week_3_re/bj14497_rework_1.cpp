#include <bits/stdc++.h>

using namespace std;

string s;
bool flag;
int n, m, sx, sy, ex, ey, cnt;
char board[301][301];
int visited[301][301];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solution(int x, int y) {
    visited[x][y] = 1;

    if (board[x][y] == '#') {
        flag = true;
        return;
    }

    if (board[x][y] == '1') {
        board[x][y] = '0';
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || ny < 1 || n < nx || m < ny) continue;
        if (visited[nx][ny]) continue;
        solution(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> sx >> sy;
    cin >> ex >> ey;

    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) board[i][j] = s[j - 1];
    }

    while (!flag) {
        memset(visited, 0, sizeof(visited));
        solution(sx, sy);
        cnt++;
    }

    cout << cnt;
}
