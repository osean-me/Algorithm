//
// Created by SeongHeon Sim on 2023/04/26.
//
#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool matrix[V][V] = {};
int visited[V] = {};

void go(int from) {
    visited[from] = 1;
    for (int i = from + 1; i < V; i++) {
        if (visited[i]) continue;
        if (matrix[from][i]) {
            cout << "matrix[" << from << "][" << i << "] 연결!\n";
            go(i);
        }
    }
}

// 문제 1. 1-2, 1-3, 3-4 무방향 간선이 존재하는 인접 행렬을 표현해보자.
int main() {
    matrix[1][2] = true;
    matrix[2][1] = true;
    matrix[1][3] = true;
    matrix[3][1] = true;
    matrix[3][4] = true;
    matrix[4][3] = true;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j]) cout << "matrix[" << i << "][" << j << "] 연결!\n";
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] && visited[i] == 0) go(i);
        }
    }
}
