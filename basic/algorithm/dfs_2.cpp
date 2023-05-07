//
// Created by SeongHeon Sim on 2023/05/07.
//
#include <bits/stdc++.h>

using namespace std;

int const V = 104;
int n = 0, m = 0, ret = 0;
int adj[V][V] = {}, visited[V][V] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
        if (adj[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) cin >> adj[y][x];
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (adj[y][x] && !visited[y][x]) {
                ret++;
                dfs(y, x);
            }
        }
    }

    cout << ret;
}
/**
 * 종화는 21세기 유명한 방구쟁이다.
 * 종화는 방구를 낄 때 "이러다... 다 죽어!!" 를 외치며 방구를 뀌는데
 * 이렇게 방귀를 뀌었을 때  방귀는 상하좌우 네방향으로 뻗어나가며 종화와 연결된 "육지"는 모두 다 오염된다.
 * "바다"로는 방구가 갈 수 없다.
 * 맵이 주어졌을 때 종화가 "이러다... 다 죽어!!"를 "최소한" 몇 번외쳐야 모든 육지를 오염시킬 수 있는지 말해보자.
 * 1은 육지며 0은 바다를 가리킨다.
*/

/**
 * 입력
 * 맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다.
*/

/**
 * 출력
 * "이러다... 다 죽어!!"를 몇 번외쳐야하는지 출력하라.
*/

/**
 * 범위
 * 1 <= N <= 100
 * 1 <= M <= 100
 */

/**
 * 5 5
 * 1 0 1 0 1
 * 1 1 0 0 1
 * 0 0 0 1 1
 * 0 0 0 1 1
 * 0 1 0 0 0
 */
