#include <bits/stdc++.h>

using namespace std;

string s;
int r, c, cnt;
char lake[1501][1501];
int visited[1501][1501];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
vector<pair<int, int>> swans;
queue<pair<int, int>> q;

void clear() { memset(visited, 0, sizeof(visited)); }

void melt(int x, int y) {
    visited[x][y] = 1;
    q.push({x, y});

    while (q.size()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        if (lake[cx][cy] == 'L') continue;

        if (lake[cx][cy] == 'X') {
            visited[cx][cy] = 1;
            lake[cx][cy] = '.';
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if (visited[nx][ny] || lake[nx][ny] != 'X') continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

void nextDay() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (lake[i][j] == '.' && !visited[i][j]) melt(i, j);
        }
    }
    clear();
}

bool validate() {
    int sx, sy;
    int ex, ey;
    tie(sx, sy) = swans[0];
    tie(ex, ey) = swans[1];

    visited[sx][sy] = 1;
    q.push(swans[0]);

    while (q.size()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        if (cx == ex && cy == ey) {
            return false;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if (visited[nx][ny] || lake[nx][ny] == 'X') continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    clear();

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            lake[i][j] = s[j];
            if (lake[i][j] == 'L') swans.push_back({i, j});
        }
    }

    while (validate()) {
        nextDay();
        cnt++;
    }

    cout << cnt;
}