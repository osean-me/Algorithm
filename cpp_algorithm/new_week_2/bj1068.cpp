#include <bits/stdc++.h>

using namespace std;

int n, m, root, cnt = 0;
vector<int> adj[51];
int visited[51];

void go(int y) {
    if (y == m || y >= n || visited[y]) return;

    int sub_cnt = 0;
    for (int x : adj[y]) {
        if (x == m) continue;
        sub_cnt++;
        go(x);
    }

    if (!sub_cnt) {
        cnt++;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (j == -1) {
            root = i;
            continue;
        }
        adj[j].push_back(i);
    }

    cin >> m;

    if (root == m) {
        cout << 0;
        return 0;
    }

    go(root);
    cout << cnt;
}