//
// Created by SeongHeon Sim on 2023/05/04.
//
#include <bits/stdc++.h>

using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u) {
    visited[u] = 1;
    cout << "u : " << u << "\n";
    for (int v: adj[u]) {
        if (visited[v] == 0) dfs(v);
    }
    cout << u << "로 부터 시작된 함수가 종료 되었습니다.\n";
    return;
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);
    dfs(1);
}
