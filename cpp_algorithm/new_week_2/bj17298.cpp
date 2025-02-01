#include <bits/stdc++.h>

using namespace std;

int n;
int adj[1000001] = {};
vector<vector<int>> nge(1000001, vector<int>());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> adj[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[j] > adj[i]) nge[adj[i]].push_back(adj[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nge[adj[i]].empty()) {
            cout << -1 << " ";
            continue;
        }
        cout << nge[adj[i]][0] << " ";
    }
}