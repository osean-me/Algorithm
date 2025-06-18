#include <bits/stdc++.h>

using namespace std;

/*
    visited[2][500001] 인 이유
        •	짝수 시간에 도달할 수 있는 위치 → 모두 짝수 시간대에서 BFS 탐색
        •	홀수 시간에 도달할 수 있는 위치 → 홀수 시간대에서 탐색
*/
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
        // time % 2 인가?
        // 현재 인덱스는 이동할 필요가 없기 떼문에
        if (visited[(time % 2)][dest] != -1) return time;

        for (int ndx : {idx + 1, idx - 1, idx * 2}) {
            // 왜 시간에 +1 을 해야 하는가?
            // > 다음 인덱스가 어디에 기록되어야 할지 알아야 하기 때문에
            int tdx = (time + 1) % 2;
            if (ndx < 0 || 500000 < ndx || visited[tdx][ndx] != -1) continue;
            visited[tdx][ndx] = time + 1;
            q.push({ndx, visited[tdx][ndx]});
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