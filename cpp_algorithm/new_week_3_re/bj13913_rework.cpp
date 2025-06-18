#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> visited(100001, -1), parents(100001, -1), paths;
queue<pair<int, int>> q;

void solution() {
    visited[n] = 0;
    q.push({n, visited[n]});

    while (q.size()) {
        int idx, time;
        tie(idx, time) = q.front();
        q.pop();

        if (idx == k) {
            // 왜 빠른 시간 여부를 체크하지 않는가?
            // > 가장 빨리 idx 가 k 가 되는 경우가 가장 빠르게 도달한 케이스
            // > 그러므로 idx == k 도달 후 메서드를 탈출해도 된다.
            for (int i = k; i != -1; i = parents[i]) paths.push_back(i);
            reverse(paths.begin(), paths.end());

            cout << time << "\n";
            for (int path : paths) cout << path << " ";
            return;
        }

        for (int nidx : {idx + 1, idx - 1, idx * 2}) {
            if (nidx < 0 || 100000 < nidx) continue;
            if (visited[nidx] == -1 || visited[nidx] == time + 1) {
                visited[nidx] = time + 1;
                parents[nidx] = idx;
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
}