#include <bits/stdc++.h>

using namespace std;

int n, m, t;
vector<int> distances, answer;
vector<pair<int, int>> houses, stores, storeComb;

int calculateDistance(pair<int, int> &house, pair<int, int> &store) {
    int y = (house.first + 1) - (store.first + 1);
    int x = (house.second + 1) - (store.second + 1);

    if (y < 0) y *= -1;
    if (x < 0) x *= -1;

    return y + x;
}

void go(int start, int depth) {
    if (depth == m) {
        for (int i = 0; i < houses.size(); i++) {
            int smallest = INT_MAX;
            for (pair<int, int> store : storeComb) {
                smallest = min(smallest, calculateDistance(houses[i], store));
            }
            distances[i] = smallest;
        }
        answer.push_back(accumulate(distances.begin(), distances.end(), 0));
        return;
    }

    for (int i = start; i < stores.size(); i++) {
        storeComb.push_back(stores[i]);
        go(i + 1, depth + 1);
        storeComb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (t == 1) houses.push_back({i, j});  // 집
            if (t == 2) stores.push_back({i, j});  // 가게
        }
    }

    distances.resize(houses.size(), INT_MAX);

    go(0, 0);
    cout << *min_element(answer.begin(), answer.end());
}