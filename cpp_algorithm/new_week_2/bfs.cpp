#include <bits/stdc++.h>

using namespace std;

vector<int> adj[25];
int visited[25] = {};

void go(int u) {
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto it = adj[u].begin(); it < adj[u].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = visited[u] + 1;
                q.push(*it);
            }
        }
    }
}

int main() {
    // 10 -> 12, 14, 16
    // 12 -> 18, 20
    // 20 -> 22, 24
    // 위의 그래프를 인접 리스트로 표현
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    go(10);

    for (int i = 10; i < 25; i++) {
        if (adj[i].size()) {
            cout << i << " : " << visited[i] << "\n";
            for (auto it = adj[i].begin(); it < adj[i].end(); it++) {
                cout << *it << " : " << visited[*it] << "\n";
            }
        }
    }

    // 왜 -1 을 해줘야 할까?
    // 총 4개의 정점을 이동한다고 가정 했을 때 사이에 이동하는 간선은 총 3개이기
    // 때문이다.
    cout << "10부터 24까지의 최단 거리는 " << visited[24] - 1 << "입니다.";
}