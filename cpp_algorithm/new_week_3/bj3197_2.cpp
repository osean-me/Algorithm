#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int MAX = 1500;
int R, C;
char lake[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> swan_q, next_swan_q;
queue<pair<int, int>> water_q, next_water_q;
pair<int, int> swans[2];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool move_swan() {
    while (!swan_q.empty()) {
        int y = swan_q.front().first;
        int x = swan_q.front().second;
        swan_q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
                continue;

            visited[ny][nx] = true;

            if (lake[ny][nx] == '.') {
                swan_q.push({ny, nx});
            } else if (lake[ny][nx] == 'X') {
                next_swan_q.push({ny, nx});
            } else if (lake[ny][nx] == 'L') {
                return true;
            }
        }
    }
    return false;
}

void melt() {
    while (!water_q.empty()) {
        int y = water_q.front().first;
        int x = water_q.front().second;
        water_q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            if (lake[ny][nx] == 'X') {
                lake[ny][nx] = '.';
                next_water_q.push({ny, nx});
            }
        }
    }
}

int main() {
    cin >> R >> C;
    int swan_idx = 0;
    for (int i = 0; i < R; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < C; ++j) {
            lake[i][j] = row[j];
            if (lake[i][j] == 'L') {
                swans[swan_idx++] = {i, j};
                water_q.push({i, j});
            } else if (lake[i][j] == '.') {
                water_q.push({i, j});
            }
        }
    }

    swan_q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = true;

    int days = 0;
    while (true) {
        if (move_swan()) {
            cout << days << endl;
            break;
        }
        melt();
        swan_q = next_swan_q;
        water_q = next_water_q;
        while (!next_swan_q.empty()) next_swan_q.pop();
        while (!next_water_q.empty()) next_water_q.pop();
        ++days;
    }

    return 0;
}