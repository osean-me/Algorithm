#include <bits/stdc++.h>

using namespace std;

const int n = 100;
vector<int> adj[n];
int visited[n] = {};

// 후위순회
void postorder(int y) {
    if (!visited[y]) {
        for (int i = 0; i < adj[y].size(); i++) postorder(adj[y][i]);
        visited[y] = 1;
        cout << "node : " << y << "\n";
    }
}

// 전위순회
void preorder(int y) {
    if (!visited[y]) {
        cout << "node : " << y << "\n";
        visited[y] = 1;
        for (int i = 0; i < adj[y].size(); i++) preorder(adj[y][i]);
    }
}

// 중위순회
void inorder(int y) {
    if (!visited[y]) {
        if (!adj[y].empty()) inorder(adj[y][0]);
        cout << "node : " << y << "\n";
        visited[y] = 1;
        if (adj[y].size() == 2) inorder(adj[y][1]);
    }
}

int main() {
    // 해당 그래프는 단방향 간선이기 때문에 visited 는 신경 쓰지 않아도 되지만
    // 수도코드에서 visited 가 기재되어 있어 함께 표현
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);

    cout << "후위순회\n";
    postorder(1);
    fill(visited, visited + n, 0);

    cout << "\n전위순회\n";
    preorder(1);
    fill(visited, visited + n, 0);

    cout << "\n중위순회\n";
    inorder(1);
}