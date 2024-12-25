#include <bits/stdc++.h>

using namespace std;

const int V = 4;
vector<int> adj[V];

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    for (int y = 0; y < V; y++) {
        cout << "y : " << y << "\n";
        for (auto it = adj[y].begin(); it < adj[y].end(); it++) {
            cout << "   x : " << *it << "\n";
        }
        cout << "\n";
    }
}