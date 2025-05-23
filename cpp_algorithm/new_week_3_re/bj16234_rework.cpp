#include <bits/stdc++.h>

using namespace std;

int n, l, r, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int board[50][50], visited[50][50];
vector<vector<pair<int, int>>> nations;
queue<pair<int, int>> points;

bool check() { return nations.size() < (n * n); }

void clear() {
    nations.clear();
    memset(visited, 0, sizeof(visited));
}

bool validate(int gap) {
    if (gap < 0) gap *= -1;
    return l <= gap && gap <= r;
}

void go(int y, int x) {
    visited[y][x] = 1;
    (*(nations.end() - 1)).push_back({y, x});
    points.push({y, x});

    while (points.size()) {
        int cy, cx;
        tie(cy, cx) = points.front();
        points.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            if (visited[ny][nx]) continue;
            if (!validate(board[cy][cx] - board[ny][nx])) continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            go(ny, nx);
            points.push({ny, nx});
        }
    }
}

void move() {
    for (vector<pair<int, int>> group : nations) {
        int sum = 0;
        for (pair<int, int> nation : group) {
            sum += board[nation.first][nation.second];
        }
        int avg = sum / group.size();
        for (pair<int, int> nation : group) {
            board[nation.first][nation.second] = avg;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    while (check()) {
        clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    nations.push_back(vector<pair<int, int>>());
                    go(i, j);
                }
            }
        }

        move();

        if (check()) ret++;
    }

    cout << ret;
}