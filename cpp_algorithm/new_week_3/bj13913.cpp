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
            cout << visited[k] << "\n";
            for (int p : path) cout << p << " ";
            return;
        }

        vector<int> next_pos = {curr + 1, curr - 1, curr * 2};
        for (int next : next_pos) {
            if (next < 0 || 100000 < next || visited[next] != -1) continue;
            visited[next] = visited[curr] + 1;
            parents[next] = curr;
            q.push(next);
        }
    }
}

int main() {
    cin >> n >> k;
    go();
}

/*
✅ BFS가 최소 이동 거리를 보장하는 이유

🔹 BFS는 “층” 단위로 탐색한다

BFS는 “현재 거리 = X”인 모든 위치를 탐색한 후, 그다음 거리를 탐색해요.
즉, queue에서 꺼낸 값은 항상 최소 횟수로 도달할 수 있는 위치라는 걸 보장합니다.

🔹 왜 처음 도착한 k가 최소값인지?
        1.	모든 경우의 수를 동시에 탐색 (한 번에 한 층씩)
        2.	따라서 가장 먼저 k에 도달한 경우가 최소 이동 횟수
        3.	이후 더 많은 이동 횟수로 k에 도착하는 경우는 고려할 필요 없음

🛠 정리: BFS가 최소 이동을 보장하는 이유
        1.	BFS는 현재 이동 횟수(거리) 기준으로 “층”을 탐색
        2.	처음 k를 발견한 순간이 최단 거리 (더 짧은 경로가 나올 수 없음)
        3.	그 이후 더 탐색해도 최소 이동보다 작아질 가능성이 없음
 */