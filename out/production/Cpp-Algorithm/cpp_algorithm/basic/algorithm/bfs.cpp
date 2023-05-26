//
// Created by SeongHeon Sim on 2023/05/07.
//
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100] = {};
int visited[100] = {};
int nodes[] = {10, 12, 14, 16, 18, 20, 22, 24};

void bfs(int here) {
    queue<int> q = queue<int>();
    visited[here] = 1;
    q.push(here);
    while (q.size()) {
        int current = q.front();
        q.pop();
        for (int there: adj[current]) {
            if (visited[there]) continue;
            visited[there] = visited[current] + 1;
            q.push(there);
        }
    }
}

int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);
    for (int n: nodes) {
        cout << n << " : " << visited[n] << "\n";
    }
    cout << "10 부터 24 까지의 최단거리는 " << visited[24] - 1 << " 입니다.";
}
