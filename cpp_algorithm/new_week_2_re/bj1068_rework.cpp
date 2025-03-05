#include <bits/stdc++.h>

using namespace std;

int n, k, r, cnt, cnode;
vector<int> nodes[51];

void go(int node) {
    if (node == k || node >= n) return;

    int scnt = 0;
    for (int child : nodes[node]) {
        if (child == k) continue;
        scnt++;
        go(child);
    }

    if (!scnt) {
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
        cin >> cnode;
        if (cnode == -1) {
            r = i;
            continue;
        }
        nodes[cnode].push_back(i);
    }

    cin >> k;
    if (k == r) {
        cout << 0;
        return 0;
    }
    go(r);
    cout << cnt;
}