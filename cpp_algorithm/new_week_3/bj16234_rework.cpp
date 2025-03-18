#include <bits/stdc++.h>

using namespace std;

int n, l, r, cnt;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int adj[51][51], visited[51][51];
vector<vector<pair<int, int>>> vvp;
vector<vector<int>> psum;
queue<pair<int, int>> q;

void go(int y, int x) {
    visited[y][x] = 1;
    q.push({y, x});
    vvp.back().push_back({y, x});
    psum.back().push_back(psum.back().back() + adj[y][x]);

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

    while (vvp.size() < (n * n)) {
        vvp.clear();
        psum.clear();
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    vvp.push_back(vector<pair<int, int>>());
                    psum.push_back(vector<int>(1, 0));
                    go(i, j);
                }
            }
        }

        for (int i = 0; i < vvp.size(); i++) {
            int sum = psum[i].back();
            int avg = sum / vvp[i].size();
            for (pair<int, int> p : vvp[i]) adj[p.first][p.second] = avg;
        }

        if (vvp.size() < (n * n)) cnt++;
    }

    cout << cnt;
}