#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool matrix[V][V], visited[V];

void recursive(int y) {
    visited[y] = 1;
    cout << y << "\n";
    for (int x = 0; x < V; x++) {
        if (visited[x]) continue;
        if (matrix[y][x]) recursive(x);
    }
}

int main() {
    matrix[1][2] = matrix[2][1] = 1;
    matrix[1][3] = matrix[3][1] = 1;
    matrix[3][4] = matrix[4][3] = 1;

    for (int y = 0; y < V; y++) {
        for (int x = 0; x < V; x++) {
            if (matrix[y][x] && !visited[y]) recursive(y);
        }
    }
}