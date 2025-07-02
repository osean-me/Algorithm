#include <bits/stdc++.h>

using namespace std;

string s;
int r, c, days;
int visited[1500][1500];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char lake[1500][1500];
vector<pair<int, int>> swans;
queue<pair<int, int>> water_q, next_water_q;
queue<pair<int, int>> swan_q, next_swan_q;

bool move() {
    while (swan_q.size()) {
        int cx, cy;
        tie(cx, cy) = swan_q.front();
        swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            if (lake[nx][ny] == '.') swan_q.push({nx, ny});
            if (lake[nx][ny] == 'X') next_swan_q.push({nx, ny});
            if (lake[nx][ny] == 'L') return false;
        }
    }

    return true;
}

void melt() {
    while (water_q.size()) {
        int cx, cy;
        tie(cx, cy) = water_q.front();
        water_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
            if (lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                next_water_q.push({nx, ny});
            }
        }
    }
}

void transfer() {
    swan_q = next_swan_q;
    while (next_swan_q.size()) next_swan_q.pop();

    water_q = next_water_q;
    while (next_water_q.size()) next_water_q.pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            lake[i][j] = s[j];
            if (lake[i][j] == 'L') swans.push_back({i, j});
            if (lake[i][j] != 'X') water_q.push({i, j});
        }
    }

    swan_q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = 1;

    while (move()) {
        melt();
        transfer();
        days++;
    }

    cout << days;
}