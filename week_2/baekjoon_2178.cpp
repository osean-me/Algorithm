//
// Created by SeongHeon Sim on 2023/04/27.
//
#include <bits/stdc++.h>

using namespace std;
int const V = 100;
int v, e = 0;
bool visited[V] = {};
vector<int> adj[V] = {};

void go(int from) {
    visited[from] = true;
    for (int i = 0; i < e; i++) {
        if (visited[i]) continue;
        if (i < v && adj[from][i]) {
            cout << from << " - " << adj[from][i] << "\n";
            go(i);
        }
    }
}

int main() {
    cin >> v >> e;

    for (int i = 0; i <= v; i++) {
        string input = "";
        getline(cin, input);
        if (!input.empty()) {
            for (int j = 0; j < e; j++) {
                if (input[j] == '1') adj[i - 1].push_back(j);
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < e; j++) {
            if (adj[i][j]) {
                cout << i << " - " << adj[i][j] << "\n";
            }
        }
        cout << "\n";
        if (!adj[i].empty() && !visited[i]) {
            go(i);
        }
    }
}
