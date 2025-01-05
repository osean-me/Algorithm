#include <bits/stdc++.h>

using namespace std;

int n;
char adj[65][65] = {};

string go(int y, int x, int size) {
    // 가장 작은 정점에 도달했을 경우, 현재의 정점의 값을 리턴한다.
    if (size == 1) return string(1, adj[y][x]);
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            // 현재 정점의 값과 다음 정점의 값이 같지 않은 경우
            // 현재 위치에서 Z 방향으로 순회
            if (adj[y][x] != adj[i][j]) {
                return "(" + go(y, x, size / 2) +
                       go(y, x + (size / 2), size / 2) +
                       go(y + (size / 2), x, size / 2) +
                       go(y + (size / 2), x + (size / 2), size / 2) + ")";
            }
        }
    }

    // 현재 위치에서 Z 방향의 정점들이 모두 같은 경우 하나의 출력만 하도록 한다.
    return string(1, adj[y][x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            adj[i][j] = s[j];
        }
    }

    cout << go(0, 0, n);
}