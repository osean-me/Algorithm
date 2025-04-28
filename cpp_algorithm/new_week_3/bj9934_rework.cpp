#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> adj;
vector<vector<int>> tree;

void go(int depth, vector<int>& nodes) {
    if (nodes.empty()) return;

    int middle = nodes.size() / 2;
    tree[depth].push_back(nodes[middle]);

    vector<int> left = vector<int>(nodes.begin(), nodes.begin() + middle);
    vector<int> right = vector<int>(nodes.begin() + middle + 1, nodes.end());

    go(depth + 1, left);
    go(depth + 1, right);
}

int main() {
    cin >> k;
    tree.resize(k);

    int cnt = pow(2, k) - 1;
    adj.resize(cnt);
    for (int i = 0; i < cnt; i++) cin >> adj[i];

    go(0, adj);

    for (int i = 0; i < k; i++) {
        for (int node : tree[i]) cout << node << " ";
        cout << "\n";
    }
}