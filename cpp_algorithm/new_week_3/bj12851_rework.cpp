#include <bits/stdc++.h>

using namespace std;

int n, k, min_time = INT_MAX, ways = 1;
vector<int> visited(100001, -1);
queue<pair<int, int>> q;

void go() {
    visited[n] = 0;
    q.push({n, 0});

    while (q.size()) {
        int curr, time;
        tie(curr, time) = q.front();
        q.pop();

        if (curr == k) {
            if (time < min_time) {
                min_time = time;
                ways = 1;
            } else {
                ways++;
            }
            continue;
        }

        vector<int> next_pos = {curr + 1, curr - 1, curr * 2};
        for (int next : next_pos) {
            if (next < 0 || 100000 < next) continue;
            if (visited[next] == -1 || visited[next] == time + 1) {
                visited[next] = time + 1;
                q.push({next, visited[next]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    go();
    cout << min_time << "\n" << ways;
}