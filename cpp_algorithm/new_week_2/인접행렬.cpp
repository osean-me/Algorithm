#include <bits/stdc++.h>

using namespace std;

int graph[21][21] = {}, q8[10][10] = {};

void go(int from) {
    for (int i = 0; i < 10; i++) {
        if (q8[from][i] == 1) {
            cout << from << "\n";
            q8[from][i] = -1;
            go(i);
        }
    }
}

int main() {
    // 3번 노드에서 5번 노드로 가는 단방향 경로
    graph[3][5] = 1;

    // 3번 노드에서 5번 노드로 가는 양방향 경로
    graph[3][5] = graph[5][3] = 1;

    // 1 -> 2 단방향 간선, 2 -> 3 단방향 간선
    bool q4[3][3] = {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}};

    // 1 -> 2 / 2 -> 3 / 3 -> 4/ 4 -> 1
    bool q5[4][4] = {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}};

    // 노드가 5개, 서로 연결 완전 그래프의 인접행렬
    bool q6[5][5] = {{0, 1, 1, 1, 1},
                     {1, 0, 1, 1, 1},
                     {1, 1, 0, 1, 1},
                     {1, 1, 1, 0, 1},
                     {1, 1, 1, 1, 0}};

    // 1 -> 3 / 3 -> 2 / 2 -> 1
    bool q7[3][3] = {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};

    // 인접행렬을 기반으로 탐색하기
    q8[1][2] = q8[2][1] = q8[1][3] = q8[3][1] = q8[4][3] = q8[3][4] = 1;
    for (int i = 0; i < 10; i++) go(i);
}