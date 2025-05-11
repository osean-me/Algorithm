#include <bits/stdc++.h>

using namespace std;

int n, m, ret = INT_MAX;
int board[50][50];
vector<pair<int, int>> visited;
vector<pair<int, int>> houses, stores;

int calculate(int hy, int hx) {
    int value = INT_MAX;

    for (pair<int, int> store : visited) {
        int y = hy - store.first;
        if (y < 0) y *= -1;
        int x = hx - store.second;
        if (x < 0) x *= -1;
        value = min(value, (y + x));
    }

    return value;
}

void go(int idx, int cnt) {
    if (cnt == m) {
        int sum = 0;
        for (pair<int, int> house : houses) {
            sum += calculate(house.first, house.second);
        }
        ret = min(ret, sum);
        return;
    }

    for (int i = idx; i < stores.size(); i++) {
        visited.push_back(stores[i]);
        go(i + 1, cnt + 1);
        visited.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) houses.push_back({j, i});  // 집
            if (board[i][j] == 2) stores.push_back({j, i});  // 치킨집
        }
    }

    go(0, 0);

    cout << ret;
}