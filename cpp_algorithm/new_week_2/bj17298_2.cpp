#include <bits/stdc++.h>

using namespace std;

int n;
int adj[1000001] = {};
vector<int> v[1000001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        for (int j = 0; j < i; j++) {
            if (adj[j] < adj[i]) v[adj[j]].push_back(adj[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[adj[i]].empty()) {
            cout << -1 << " ";
            continue;
        }
        cout << v[adj[i]][0] << " ";
    }
}