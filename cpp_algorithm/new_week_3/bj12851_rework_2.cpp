#include <bits/stdc++.h>

using namespace std;

int n, k, min_time = INT_MAX, cnt;
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
                cnt = 1;
            } else {
                cnt++;
            }
        }

        vector<int> npos = {curr + 1, curr - 1, curr * 2};
        for (int next : npos) {
            if (next < 0 || 100000 < next) continue;
            if (visited[next] == -1 || visited[next] == time + 1) {
                visited[next] = time + 1;
                q.push({next, visited[next]});
            }
        }
    }
}

int main() {
    cin >> n >> k;
    go();
    cout << min_time << "\n" << cnt;
}