#include <bits/stdc++.h>

using namespace std;

string s;
bool flag;
int n, m, sx, sy, ex, ey, cnt;
char board[301][301];
int visited[301][301];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void solution() {
    memset(visited, 0, sizeof(visited));
    visited[sx][sy] = 1;
    q.push({sx, sy});

    while (q.size()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        if (cx == ex && cy == ey) {
            flag = true;
            break;
        }

        if (board[cx][cy] == '1') {
            board[cx][cy] = '0';
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
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
        solution();
        cnt++;
    }

    cout << cnt;
}