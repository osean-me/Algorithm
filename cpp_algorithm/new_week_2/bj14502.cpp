#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, adj[10][10] = {}, visited[10][10] = {};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> empty_areas;

void clean() {}

// 최초 아이디어
// 1. 벽을 세울 수 있는 모든 경우의 수를 처리하자 > 순열을 이용하는건 어떨까?
// 2. 벽을 세운 후 DFS 를 이용해 바이러스가 퍼질 수 있는 영역에 마킹
// 3. 마킹이 끝나면 남은 안전 지역을 찾아서 카운트

// 아이디어의 문제점
// 1. 조합을 사용해야 하는데 별도의 함수를 구현하기가 싫어 순열을 사용한 죄
// 2. DFS 처리 중 기저 사례 조건 제대로 확인하지 않은 죄

// 다시 체크해야 할 부분
// 1. 조합을 어떻게 구현 했었는지 복습하기
// 2. 강의 다시 보면서 복습하기
void go(int y, int x) {
    visited[y][x]++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
        if (!adj[ny][nx] && !visited[ny][nx]) {
            adj[ny][nx] = 4;
            go(ny, nx);
        }
    }
}

void count() {
    // 카운트 초기화
    int c = 0;
    // 방문 기록 초기화
    memset(visited, 0, sizeof(visited));

    // 바이러스 전파
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 2 && !visited[i][j]) go(i, j);
        }
    }

    // 남은 안전 지역 체크 및 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!adj[i][j]) c++;
            if (adj[i][j] == 4) adj[i][j] = 0;
        }
    }

    cnt = max(cnt, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (!adj[i][j]) empty_areas.push_back({i, j});
        }
    }

    for (int i = 0; i < empty_areas.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                adj[empty_areas[i].first][empty_areas[i].second] = 3;
                adj[empty_areas[j].first][empty_areas[j].second] = 3;
                adj[empty_areas[k].first][empty_areas[k].second] = 3;
                count();
                adj[empty_areas[i].first][empty_areas[i].second] = 0;
                adj[empty_areas[j].first][empty_areas[j].second] = 0;
                adj[empty_areas[k].first][empty_areas[k].second] = 0;
            }
        }
    }

    cout << cnt;
}