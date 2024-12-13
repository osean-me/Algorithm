#include <bits/stdc++.h>

using namespace std;

int n, white_cnt = 0, blue_cnt = 0;
vector<vector<int>> paper(129, vector<int>(129, 0));

bool isSameColor(int y, int x, int dist) {
    int color = paper[y][x];

    for (int i = y; i < y + dist; i++) {
        for (int j = x; j < x + dist; j++) {
            if (color != paper[i][j]) return false;
        }
    }

    return true;
}

void dividePaper(int y, int x, int dist) {
    if (isSameColor(y, x, dist) || dist == 1) {
        int color = paper[y][x];
        if (color == 0) white_cnt++;
        if (color == 1) blue_cnt++;
    } else {
        dividePaper(y, x, dist / 2);
        dividePaper(y, x + dist / 2, dist / 2);
        dividePaper(y + dist / 2, x, dist / 2);
        dividePaper(y + dist / 2, x + dist / 2, dist / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> paper[i][j];
    }

    dividePaper(0, 0, n);
    cout << white_cnt << "\n" << blue_cnt;
}