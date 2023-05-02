//
// Created by SeongHeon Sim on 2023/05/03.
//
#include <bits/stdc++.h>

using namespace std;

// 4 방향인 경우는 4번 반복
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 8 방향인 경우 8번 반복
const int ddy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int y = 1, x = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << "y : " << ny << " / x : " << nx << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 8; i++) {
        int ny = y + ddy[i];
        int nx = x + ddx[i];
        cout << "y : " << ny << " / x : " << nx << "\n";
    }
}
