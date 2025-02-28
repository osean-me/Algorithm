#include <bits/stdc++.h>

using namespace std;

int n, t, r, p, cnt;
vector<int> nodes[51];

void go(int node) {
    if (node == t || node >= n) return;

    int scnt = 0;
    for (int child : nodes[node]) {
        if (child == t) continue;
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
        cin >> p;
        if (p == -1) {
            r = i;
            continue;
        }
        nodes[p].push_back(i);
    }

    cin >> t;

    if (t == r) {
        cout << 0;
        return 0;
    }

    go(r);
    cout << cnt;
}