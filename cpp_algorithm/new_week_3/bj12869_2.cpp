#include <bits/stdc++.h>

using namespace std;

struct P {
    int x, y, z;
};

int n, visited[61][61][61];
vector<int> scv(3, 0), damages = {1, 3, 9};
vector<vector<int>> damage_map;
queue<P> q;

int go(int x, int y, int z) {
    visited[x][y][z] = 1;
    q.push({x, y, z});

    while (q.size()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int cz = q.front().z;
        q.pop();

        if (visited[0][0][0]) break;
        for (vector<int> damage : damage_map) {
            int nx = max(0, cx - damage[0]);
            int ny = max(0, cy - damage[1]);
            int nz = max(0, cz - damage[2]);

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
    for (int i = 0; i < n; i++) cin >> scv[i];

    do {
        damage_map.push_back(vector<int>(damages));
    } while (next_permutation(damages.begin(), damages.end()));

    cout << go(scv[0], scv[1], scv[2]);
}