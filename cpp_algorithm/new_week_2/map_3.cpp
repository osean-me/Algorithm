#include <bits/stdc++.h>

using namespace std;

const int n = 3;
int adj[n][n], visited[n][n];
// 4방향인 경우, {0, 0}, {1, 0} 만 출력
// int dy[] = {-1, 0, 1, 0};
// int dx[] = {0, 1, 0, -1};
// 4방향 + 대각선 포함
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << "\n";
    // 4방향인 경우
    // for (int i = 0; i < 4; i++) {
    // 4방향 + 대각선 포함
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        if (adj[ny][nx] == 0 || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    // 1. 3X3 맵 입력
    // 2. 맵은 1 혹은 0 으로 구성
    // 3. {0, 0} = 1
    // 4. 4방향을 기준으로 한 칸씩 탐색
    // 5. 방문한 정점은 다시 방문하지 않는다.
    // 6. 방문한 좌표는 출력하라.
    // 7. 1은 방문 가능, 0은 방문 불가능
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> adj[i][j];
    }

    // {0, 0} = 1
    go(0, 0);
}