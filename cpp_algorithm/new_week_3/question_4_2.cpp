#include <bits/stdc++.h>

using namespace std;

int n, t, k, ret;
vector<int> container;
vector<int> visited;
vector<int> adj[101];

void go(int i) {
    if (container.size() == t) {
        for (int node : container) cout << char(node + 'A') << " ";
        cout << "\n";
        return;
    }

    for (int node : adj[i]) {
        if (visited[node]) continue;
        visited[node]++;
        container.push_back(node);
        go(node);
        container.pop_back();
        visited[node] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == -1) continue;
        adj[k].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int j : adj[i]) cout << j << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        visited[i]++;
        container.push_back(i);
        go(i);
        container.pop_back();
        visited[i] = 0;
    }
}