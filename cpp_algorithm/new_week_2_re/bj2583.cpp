#include <bits/stdc++.h>

using namespace std;

int n, m, r, sy, sx, fy, fx, cnt, ccnt;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> answer;

void go(int y, int x) {
    visited[y][x]++;
    ccnt++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (adj[ny][nx] || visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;

    for (int i = 0; i < r; i++) {
        cin >> sx >> sy >> fx >> fy;
        for (int y = sy; y < fy; y++) {
            for (int x = sx; x < fx; x++) adj[y][x]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!adj[i][j] && !visited[i][j]) {
                go(i, j);
                answer.push_back(ccnt);
                cnt++;
            }
            ccnt = 0;
        }
    }

    sort(answer.begin(), answer.end());

    cout << cnt << "\n";
    for (int c : answer) cout << c << " ";
}