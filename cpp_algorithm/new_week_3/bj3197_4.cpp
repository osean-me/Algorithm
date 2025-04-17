#include <bits/stdc++.h>

using namespace std;

const int MAX = 1500;

string row;
int r, c, days;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int visited[MAX][MAX];
char lake[MAX][MAX];

vector<pair<int, int>> swans;
queue<pair<int, int>> swan_q, next_swan_q;
queue<pair<int, int>> water_q, next_water_q;

bool move_swan() {
    while (swan_q.size()) {
        int cy, cx;
        tie(cy, cx) = swan_q.front();
        swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx || visited[ny][nx]) {
                continue;
            }

            visited[ny][nx] = 1;

            if (lake[ny][nx] == '.') {
                swan_q.push({ny, nx});
            } else if (lake[ny][nx] == 'X') {
                next_swan_q.push({ny, nx});
            } else {
                return true;
            }
        }
    }

    return false;
}

void melt() {
    while (water_q.size()) {
        int cy, cx;
        tie(cy, cx) = water_q.front();
        water_q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (lake[ny][nx] == 'X') {
                lake[ny][nx] = '.';
                next_water_q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> row;
        for (int j = 0; j < c; j++) {
            lake[i][j] = row[j];
            if (lake[i][j] == 'L') swans.push_back({i, j});
            if (lake[i][j] != 'X') water_q.push({i, j});
        };
    }

    swan_q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = 1;

    while (true) {
        if (move_swan()) {
            cout << days << endl;
            break;
        }

        melt();
        swan_q = next_swan_q;
        water_q = next_water_q;
        while (next_swan_q.size()) next_swan_q.pop();
        while (next_water_q.size()) next_water_q.pop();

        ++days;
    }
}