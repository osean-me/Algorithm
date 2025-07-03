#include <bits/stdc++.h>

using namespace std;

int k;
vector<int> nodes;
vector<vector<int>> tree;

void solution(int idx, int depth) {
    tree[depth].push_back(nodes[idx]);

    if (depth == 0) {
        return;
    }

    int next = depth - 1;
    int offset = (int)pow(2, next);
    solution(idx - offset, next);
    solution(idx + offset, next);
}

void print() {
    reverse(tree.begin(), tree.end());
    for (auto nums : tree) {
        for (int num : nums) cout << num << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    tree.resize(k);

    int total = ((int)pow(2, k)) - 1;
    nodes.resize(total);

    for (int i = 0; i < total; i++) cin >> nodes[i];

    solution(total / 2, k - 1);
    print();
}