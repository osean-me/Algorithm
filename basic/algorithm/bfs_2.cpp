#include <bits/stdc++.h>
using namespace std;

int const V = 104;
int y = 0, x = 0, n = 0, m = 0, sy = 0, sx = 0, ey = 0, ex = 0;
int a[V][V] = {}, visited[V][V] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int> > q = queue<pair<int, int> >();

void bfs(int sy, int sx) {
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (!a[ny][nx] || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    // 지도 크기
    cin >> n >> m;
    // 시작지점
    cin >> sy >> sx;
    // 종료지점
    cin >> ey >> ex;

    // 지도 그리기
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) cin >> a[x][y];
    }
    // 깊이 우선 탐색 시작
    bfs(sy, sx);
    // 시작지점부터 종료지점까지의 최단 거리 계산
    cout << visited[ey][ex] << '\n';
}

/**
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
*/