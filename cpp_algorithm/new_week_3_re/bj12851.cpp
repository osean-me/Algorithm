#include <bits/stdc++.h>

using namespace std;

int n, k, min_time = INT_MAX, ways = 1;
vector<int> visited(100001, -1);
queue<pair<int, int>> q;

void solution() {
    visited[n] = 0;
    q.push({0, n});

    while (q.size()) {
        int t, i;
        tie(t, i) = q.front();
        q.pop();

        if (i == k) {
            if (t < min_time) {
                min_time = t;
                ways = 1;
            } else if (t == min_time) {
                ways++;
            }
            continue;
        }

        vector<int> next_i = {i - 1, i + 1, i * 2};
        for (int ni : next_i) {
            if (ni < 0 || 100000 < ni) continue;
            if (visited[ni] == -1 || visited[ni] == t + 1) {
                visited[ni] = t + 1;
                q.push({visited[ni], ni});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    solution();
    cout << min_time << "\n" << ways;
}