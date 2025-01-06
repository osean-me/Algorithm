#include <bits/stdc++.h>

using namespace std;

int n, m, k, t = 0, c = 0;
int adj[101][101] = {}, visitied[101][101] = {};
int edges[4] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> cnt;

void go(int y, int x) {
    visitied[y][x] = 1;
    c++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || m <= ny || n <= nx) continue;
        if (adj[ny][nx] || visitied[ny][nx]) continue;
        go(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) cin >> edges[j];

        for (int y = edges[0]; y < edges[2]; y++) {
            for (int x = edges[1]; x < edges[3]; x++) {
                adj[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (!adj[y][x] && !visitied[y][x]) {
                t++;
                go(y, x);
                cnt.push_back(c);
                c = 0;
            }
        }
    }

    cout << t << "\n";
    sort(cnt.begin(), cnt.end());
    for (int c : cnt) cout << c << " ";
}