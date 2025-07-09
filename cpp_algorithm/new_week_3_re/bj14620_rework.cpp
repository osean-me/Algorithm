#include <bits/stdc++.h>

using namespace std;

int n, price = INT_MAX;
int board[10][10], visited[10][10];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

bool validate(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || n <= nx || ny < 0 || n <= ny) return false;
        if (visited[nx][ny]) return false;
    }

    return true;
}

int plant(int x, int y) {
    int cost = board[x][y];
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = 1;
        cost += board[nx][ny];
    }

    return cost;
}

void unplant(int x, int y) {
    visited[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = 0;
    }
}

void solution(int depth, int cost) {
    if (depth >= 3) {
        price = min(price, cost);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!validate(i, j)) continue;
            solution(depth + 1, cost + plant(i, j));
            unplant(i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    solution(0, 0);
    cout << price;
}