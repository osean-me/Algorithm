//
// Created by SeongHeon Sim on 2023/05/03.
//
#include <bits/stdc++.h>

using namespace std;

const int size = 3;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int matrix[size][size] = {}, visited[size][size] = {};

void next(int y, int x) {
    if (y == -1 || x == -1 || y == size || x == size) return;
    if (visited[y][x] || matrix[y][x] == 0) return;
    visited[y][x] = 1;
    cout << y << " : " << x << "\n";
    for (int i = 0; i < 4; i++) next(y + dy[i], x + dx[i]);
}

// 3X3 지도
// 한 번 방문하면 다시 방문하지 않는다.
// 값이 1인 곳만 방문 가능하다.
int main() {
    for (int y = 0; y < size; y++) for (int x = 0; x < size; x++) cin >> matrix[y][x];
    next(0, 0);
}
