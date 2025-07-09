#include <bits/stdc++.h>

using namespace std;

int r, c, k, cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visited[5][5];
char board[5][5];
queue<pair<int, int>> q;

void count() {
    if (visited[0][c - 1] != k) return;
    cnt++;
}

void solution(int x, int y) {
    q.push({x, y});

    while (q.size()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        if (cx == 0 && cy == (c - 1)) {
            count();
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if (visited[nx][ny] || board[nx][ny] == 'T') continue;
            visited[nx][ny] = visited[cx][cy] + 1;
            solution(nx, ny);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cin >> board[i][j];
    }

    visited[r - 1][0] = 1;
    solution(r - 1, 0);

    cout << cnt;
}