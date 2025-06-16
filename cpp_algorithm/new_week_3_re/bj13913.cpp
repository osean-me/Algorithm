#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> visited(100001, -1), parents(100001, -1), paths;
queue<int> q;

void solution() {
    visited[n] = 0;
    q.push(n);

    while (q.size()) {
        int idx = q.front();
        q.pop();

        if (idx == k) {
            for (int i = k; i != -1; i = parents[i]) paths.push_back(i);
            reverse(paths.begin(), paths.end());
            cout << visited[idx] << "\n";
            for (int path : paths) cout << path << " ";
        }

        vector<int> next_pos = {idx + 1, idx - 1, idx * 2};
        for (int nidx : next_pos) {
            if (nidx < 0 || 100000 < nidx || visited[nidx] != -1) continue;
            visited[nidx] = visited[idx] + 1;
            parents[nidx] = idx;
            q.push(nidx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    solution();
}