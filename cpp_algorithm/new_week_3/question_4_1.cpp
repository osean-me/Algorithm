#include <bits/stdc++.h>

using namespace std;

int n, k, t, r;
vector<int> answer;
vector<vector<int>> adj;

void go(int i) {
    answer.push_back(i);
    cout << "index : " << i << ", count : " << answer.size() << "\n";

    if (answer.size() == t) {
        for (int node : answer) cout << node << " ";
        cout << "\n";
        answer.pop_back();
        return;
    }

    for (int node : adj[i]) go(node);
    answer.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == -1) {
            r = i;
            continue;
        }
        adj[k].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (int j : adj[i]) cout << j << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++) go(i);
}