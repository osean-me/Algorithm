#include <bits/stdc++.h>

using namespace std;

int n;
int scv[3], dp[61][61][61];
vector<vector<int>> attack = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1},
                              {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};

int go(int a, int b, int c) {
    a = max(0, a);
    b = max(0, b);
    c = max(0, c);
    if (a == 0 && b == 0 && c == 0) return 0;
    int &ret = dp[a][b][c];
    if (ret) return ret;

    ret = INT_MAX;
    for (auto damage : attack) {
        ret = min(ret, go(a - damage[0], b - damage[1], c - damage[2]) + 1);
    }

    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> scv[i];

    cout << go(scv[0], scv[1], scv[2]);
}