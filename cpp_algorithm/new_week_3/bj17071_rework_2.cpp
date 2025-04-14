#include <bits/stdc++.h>

using namespace std;

int n, k, visited[2][500001];
queue<pair<int, int>> q;

int go() {
    memset(visited, 0, sizeof(visited));
    visited[0][n] = 1;
    q.push({n, 0});

    while (q.size()) {
        int curr, time;
        tie(curr, time) = q.front();
        q.pop();

        int dest = k + time * (time + 1) / 2;
        if (500000 < dest) return -1;
        if (visited[time % 2][dest]) return time;

        for (int next : {curr + 1, curr - 1, curr * 2}) {
            if (next < 0 || 500000 < next) continue;
            if (visited[(time + 1) % 2][next]) continue;
            visited[(time + 1) % 2][next] = time + 1;
            q.push({next, time + 1});
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;
    cout << go();
}