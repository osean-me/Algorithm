//
// Created by SeongHeon Sim on 2023/04/25.
//
#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool matrix[V][V] = {};

void recursive(int i, int j) {
    if (i == V || j == V) return;

    if (!matrix[i][j]) {
        matrix[i][j] = true;
        matrix[j][i] = true;
        if (j == (V - 1)) {
            i++;
            j = 0;
        } else j++;
        recursive(i, j);
    } else recursive(i, j + 1);
}

int main() {
    recursive(0, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << "\n";
        }
    }
}
