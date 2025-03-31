#include <bits/stdc++.h>

using namespace std;

int n, visited[61][61][61];
vector<int> scv, defaultDamage = {1, 3, 9};
vector<vector<int>> damageMap;
queue<vector<int>> q;

int go(int x, int y, int z) {
    visited[x][y][z] = 1;
    q.push({x, y, z});

    while (q.size()) {
        int cx = q.front()[0];
        int cy = q.front()[1];
        int cz = q.front()[2];
        q.pop();

        if (visited[0][0][0]) break;
        for (vector<int> damages : damageMap) {
            int nx = max(0, cx - damages[0]);
            int ny = max(0, cy - damages[1]);
            int nz = max(0, cz - damages[2]);

            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[cx][cy][cz] + 1;
            q.push({nx, ny, nz});
        }
    }

    return visited[0][0][0] - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    scv.resize(n);
    for (int i = 0; i < n; i++) cin >> scv[i];

    do {
        damageMap.push_back(vector<int>(defaultDamage));
    } while (next_permutation(defaultDamage.begin(), defaultDamage.end()));

    cout << go(scv[0], scv[1], scv[2]);
}