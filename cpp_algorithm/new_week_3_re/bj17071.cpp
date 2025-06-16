#include <bits/stdc++.h>

using namespace std;

int n, k, visited[2][500001];
queue<pair<int, int>> q;

int solution() {
    memset(visited, -1, sizeof(visited));
    visited[0][n] = 0;
    q.push({n, visited[0][n]});

    while (q.size()) {
        int idx, time;
        tie(idx, time) = q.front();
        q.pop();

        int dest = k + time * (time + 1) / 2;
        if (500000 < dest) return -1;
        if (visited[time % 2][dest] != -1) return time;

        for (int nidx : {idx + 1, idx - 1, idx * 2}) {
            int t = (time + 1) % 2;
            if (nidx < 0 || 500000 < nidx) continue;
            if (visited[t][nidx] != -1) continue;

            visited[t][nidx] = time + 1;
            q.push({nidx, visited[t][nidx]});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cout << solution();
}