//
// Created by SeongHeon Sim on 2023/04/24.
//
#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool matrix[V][V] = {};

// 문제 1. 1-2, 1-3, 3-4 무방향 간선이 존재하는 인접 행렬을 표현해보자.
int main() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            bool isOneToTwo = i == 1 && j == 2;
            bool isOneToThree = i == 1 && j == 3;
            bool isThreeToFour = i == 3 && j == 4;

            if (isOneToTwo || isOneToThree || isThreeToFour) {
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << "\n";
        }
    }
}
