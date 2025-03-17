#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> distances, answer;
vector<pair<int, int>> houses, stores, comb;

int calDistance(pair<int, int> &house, pair<int, int> &store) {
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
            for (pair<int, int> store : comb) {
                smallest = min(smallest, calDistance(houses[i], store));
            }
            distances[i] = smallest;
        }
        answer.push_back(accumulate(distances.begin(), distances.end(), 0));
        return;
    }

    for (int i = start; i < stores.size(); i++) {
        comb.push_back(stores[i]);
        go(i + 1, depth + 1);
        comb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> k;
            if (k == 1) houses.push_back({y, x});
            if (k == 2) stores.push_back({y, x});
        }
    }

    distances.resize(houses.size());
    go(0, 0);
    cout << *min_element(answer.begin(), answer.end());
}