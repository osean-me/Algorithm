#include <bits/stdc++.h>

using namespace std;

int n, m, mx;
int visited[10001], results[10001];
vector<vector<int>> adj(10001, vector<int>());

void go(int y, int &cnt) {
    visited[y]++;
    if (adj[y].empty()) return;
    for (int x : adj[y]) {
        if (visited[x]) continue;
        go(x, ++cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        go(i, cnt);
        results[i] = cnt;
        mx = max(results[i], mx);
    }

    for (int i = 1; i <= n; i++) {
        if (results[i] == mx) cout << i << " ";
    }
}