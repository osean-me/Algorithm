#include <bits/stdc++.h>

using namespace std;

int n, m, r, cnt = 0;
int visited[51];
vector<vector<int>> adj(51, vector<int>());

void go(int y) {
    visited[y]++;
    if (adj[y].empty()) {
        cnt++;
        return;
    }

    for (int x : adj[y]) {
        if (visited[x] || x == m) continue;
        go(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;

        if (node == -1) {
            r = i;
            continue;
        }

        adj[node].push_back(i);
    }

    cin >> m;

    if (r == m) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] == m) adj[i].erase(adj[i].begin() + j);
        }
    }
    adj[m].clear();

    go(r);
    cout << cnt;
}