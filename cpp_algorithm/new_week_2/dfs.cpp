#include <bits/stdc++.h>

using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n] = {};

void dfs(int u) {
    cout << u << "\n";
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    cout << u << "로 부터 시작된 함수가 종료되었습니다.\n";
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    dfs(1);
}