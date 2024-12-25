#include <bits/stdc++.h>

using namespace std;

const int V = 10;
vector<int> matrix[V];
int visited[V];

void recursive(int y) {
    visited[y] = 1;
    cout << y << "\n";
    for (int vertex : matrix[y]) {
        if (visited[vertex]) continue;
        recursive(vertex);
    }
}

int main() {
    matrix[1].push_back(2);
    matrix[1].push_back(3);

    matrix[2].push_back(1);

    matrix[3].push_back(1);
    matrix[3].push_back(4);

    matrix[4].push_back(3);

    for (int y = 0; y < V; y++) {
        if (!matrix[y].empty() && !visited[y]) recursive(y);
    }
}