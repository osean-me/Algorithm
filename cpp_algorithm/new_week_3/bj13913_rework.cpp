#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> visited(100001, -1), parents(100001, -1), path;
queue<int> q;

void go() {
    visited[n] = 0;
    q.push(n);

    while (q.size()) {
        int curr = q.front();
        q.pop();

        if (curr == k) {
            for (int i = k; i != -1; i = parents[i]) path.push_back(i);
            reverse(path.begin(), path.end());
            cout << (path.size() - 1) << "\n";
            for (int p : path) cout << p << " ";
            return;
        }

        vector<int> npos = {curr + 1, curr - 1, curr * 2};
        for (int next : npos) {
            if (next < 0 || 100000 < next) continue;
            if (visited[next] == -1 || visited[next] == visited[curr] + 1) {
                visited[next] = visited[curr] + 1;
                parents[next] = curr;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> k;
    go();
}