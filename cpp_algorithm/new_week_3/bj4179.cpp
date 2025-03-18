#include <bits/stdc++.h>

using namespace std;

int r, c, ret, cy, cx;
char adj[1001][1001];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
pair<int, int> jihoon;
vector<vector<int>> fire_check(1001, vector<int>(1001, INT_MAX)),
    person_check(1001, vector<int>(1001, 0));
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            adj[i][j] = s[j];
            if (adj[i][j] == 'J') jihoon = {i, j};
            if (adj[i][j] == 'F') {
                fire_check[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (adj[ny][nx] == '#' || fire_check[ny][nx] != INT_MAX) continue;
            fire_check[ny][nx] = fire_check[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    person_check[jihoon.first][jihoon.second] = 1;
    q.push(jihoon);
    while (q.size()) {
        tie(cy, cx) = q.front();
        q.pop();

        if (cy == r - 1 || cx == c - 1 || cy == 0 || cx == 0) {
            ret = person_check[cy][cx];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (adj[ny][nx] == '#' || person_check[ny][nx]) continue;
            if (fire_check[ny][nx] <= person_check[cy][cx] + 1) continue;
            person_check[ny][nx] = person_check[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    cout << (ret ? to_string(ret) : "IMPOSSIBLE");
}