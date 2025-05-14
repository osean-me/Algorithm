#include <bits/stdc++.h>

using namespace std;

int n, m, ret = INT_MAX;
int board[50][50];
vector<pair<int, int>> houses, stores, target;

int convert(int value) {
    if (value < 0) return value * -1;
    return value;
}

int calDistance(pair<int, int> &house, pair<int, int> &store) {
    int y = convert(house.first - store.first);
    int x = convert(house.second - store.second);
    return y + x;
}

int getDistance() {
    int totalDistance = 0;

    for (pair<int, int> house : houses) {
        int distance = INT_MAX;
        for (pair<int, int> store : target) {
            distance = min(distance, calDistance(house, store));
        }
        totalDistance += distance;
    }

    return totalDistance;
}

void go(int idx) {
    if (target.size() == m) {
        ret = min(ret, getDistance());
        return;
    }

    for (int i = idx; i < stores.size(); i++) {
        target.push_back(stores[i]);
        go(i + 1);
        target.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) houses.push_back({j, i});
            if (board[i][j] == 2) stores.push_back({j, i});
        }
    }

    go(0);
    cout << ret;
}