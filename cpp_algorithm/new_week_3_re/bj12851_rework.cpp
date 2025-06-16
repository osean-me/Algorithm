#include <bits/stdc++.h>

using namespace std;

int n, k, min_time = INT_MAX, ways;
vector<int> visited(100001, -1);
queue<pair<int, int>> q;

void solution() {
    visited[n] = 0;
    q.push({n, visited[n]});

    while (q.size()) {
        int idx, time;
        tie(idx, time) = q.front();
        q.pop();

        if (idx == k) {
            if (time < min_time) {
                min_time = time;
                ways = 1;
            } else if (time == min_time) {
                ways++;
            }
            continue;
        }

        vector<int> next_pos = {idx + 1, idx - 1, idx * 2};
        for (int nidx : next_pos) {
            if (nidx < 0 || 100000 < nidx) continue;
            if (visited[nidx] == -1 || visited[nidx] == time + 1) {
                visited[nidx] = time + 1;
                q.push({nidx, visited[nidx]});
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
    cout << min_time << '\n' << ways;
}