#include <bits/stdc++.h>

using namespace std;

int n;
int adj[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
vector<int> container;

void go(int y, int x) {
    if (y == n - 1 && x == n - 1) {
        for (int money : container) cout << money << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        container.push_back(adj[ny][nx]);
        go(ny, nx);
        container.pop_back();
        visited[ny][nx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> adj[i][j];
    }

    container.push_back(adj[0][0]);
    go(0, 0);
}