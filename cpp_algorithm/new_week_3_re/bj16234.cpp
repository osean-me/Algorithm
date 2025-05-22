#include <bits/stdc++.h>

using namespace std;

int n, l, r, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int board[50][50], flag[50][50];
vector<vector<pair<int, int>>> visited;
queue<pair<int, int>> points;

bool check() { return visited.size() < (n * n); }

bool validate(int gap) {
    if (gap < 0) gap *= -1;
    return l <= gap && gap <= r;
}

void clear() {
    visited.clear();
    memset(flag, 0, sizeof(flag));
}

void go(int y, int x) {
    flag[y][x] = 1;
    (*(visited.end() - 1)).push_back({y, x});
    points.push({y, x});

    while (points.size()) {
        int cy, cx;
        tie(cy, cx) = points.front();
        points.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            if (flag[ny][nx]) continue;
            if (!validate(board[cy][cx] - board[ny][nx])) continue;

            flag[ny][nx] = flag[cy][cx] + 1;
            go(ny, nx);
            points.push({ny, nx});
        }
    }
}

void calculate() {
    for (vector<pair<int, int>> nations : visited) {
        int sum = 0;
        for (pair<int, int> nation : nations) {
            sum += board[nation.first][nation.second];
        }
        int avg = sum / nations.size();
        for (pair<int, int> nation : nations) {
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
                if (flag[i][j]) continue;
                visited.push_back(vector<pair<int, int>>());
                go(i, j);
            }
        }
        calculate();
        if (check()) ret++;
    }
    cout << ret;
}