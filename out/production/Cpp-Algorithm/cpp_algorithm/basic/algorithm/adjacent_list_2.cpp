//
// Created by SeongHeon Sim on 2023/04/27.
//
#include <bits/stdc++.h>

using namespace std;

// 문제 1. 정점은 0 ~ 9까지 총 10개가 존재한다. 1-2, 1-3, 3-4 경로가 있을 때 인접 리스트로 표현하시오.
int const V = 10;
vector<int> adj[V] = {};
bool visited[V] = {};

// 문제 2. 0번부터 방문하지 않은 노드를 찾은 후 방문 체크하고, 연결된 노드에 방문한다.
// 이 때, 이미 방문한 노드는 방문하지 않도록 하는 재귀함수를 만드시오.
void go(int from) {
    visited[from] = true;
    for (int n: adj[from]) {
        if (visited[n]) continue;
        cout << from << " - " << n << "\n";
        go(n);
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);

    adj[3].push_back(1);
    adj[3].push_back(4);

    adj[4].push_back(3);

    for (int i = 0; i < V; i++) {
        for (int n: adj[i]) {
            cout << i << "와 " << n << "은 연결되어 있다.\n";
        }
    }

    for (int i = 0; i < V; i++) {
        if (!adj[i].empty() && !visited[i]) go(i);
    }
}
