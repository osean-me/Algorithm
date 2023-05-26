//
// Created by SeongHeon Sim on 2023/04/27.
//
#include <bits/stdc++.h>

using namespace std;

int const V = 10;
vector<int> adj[V] = {};

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    for (int i = 0; i < V; i++) {
        cout << "adj[" << i << "] ::";
        for (int v: adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
