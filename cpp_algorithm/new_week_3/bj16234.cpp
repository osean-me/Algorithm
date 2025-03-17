#include <bits/stdc++.h>

using namespace std;

int n, l, r, cnt;
int adj[51][51], visited[51][51];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<pair<int, int>> vp;
vector<vector<pair<int, int>>> vvp;
queue<pair<int, int>> q;

void go(int y, int x) {
    visited[y][x] = 1;
    (*(vvp.end() - 1)).push_back({y, x});
    q.push({y, x});

    while (q.size()) {
        int cy, cx, cv;
        tie(cy, cx) = q.front();
        cv = adj[cy][cx];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
            if (visited[ny][nx]) continue;

            int nv = adj[ny][nx];
            int gap = cv - nv;
            if (gap < 0) gap *= -1;
            if (gap < l || r < gap) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            go(ny, nx);
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> adj[i][j];
    }

    // vvp 사이즈가 n*n 와 같은 경우, 더이상 인구 이동은 없다.
    while (vvp.size() < (n * n)) {
        // 순회가 시작되면 값 초기화
        vvp.clear();
        memset(visited, 0, sizeof(visited));

        // 모든 노드를 순회하면서
        // 각 나라와 연결된(국경을 열 수 있는) 나라의 좌표를 담는다.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vvp.push_back(vector<pair<int, int>>());
                    go(i, j);
                }
            }
        }

        // 첫 번째 vector 는 현재 연결된 나라들의 좌표 리스트 내역
        // 즉, vvp 의 사이즈는 현재 연결된 그래프의 리스트를 나타낸다.
        for (vector<pair<int, int>> vp : vvp) {
            int sum = 0;
            int avg = 0;
            // 두 번째 vector 는
            for (pair<int, int> p : vp) sum += adj[p.first][p.second];
            avg = sum / vp.size();
            for (pair<int, int> p : vp) adj[p.first][p.second] = avg;
        }

        if (vvp.size() < (n * n)) cnt++;
    }

    cout << cnt;
}