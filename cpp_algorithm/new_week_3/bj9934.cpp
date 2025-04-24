#include <bits/stdc++.h>

using namespace std;

int k, l;
vector<vector<int>> tree(10, vector<int>());

void go(vector<int>& nodes, int level) {
    if (nodes.empty()) return;

    int mid = nodes.size() / 2;
    tree[level].push_back(nodes[mid]);

    vector<int> left(nodes.begin(), nodes.begin() + mid);
    vector<int> right(nodes.begin() + mid + 1, nodes.end());

    go(left, level + 1);
    go(right, level + 1);
}

int main() {
    cin >> k;
    l = pow(2, k) - 1;
    vector<int> input(l);

    for (int i = 0; i < l; i++) cin >> input[i];

    go(input, 0);

    for (int i = 0; i < k; i++) {
        for (int node : tree[i]) cout << node << ' ';
        cout << '\n';
    }
}