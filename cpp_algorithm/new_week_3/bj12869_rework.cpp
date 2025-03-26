#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MAX;
vector<int> scv;
unordered_map<string, int> memo;

string createKey(vector<int> v) {
    return accumulate(next(v.begin()), v.end(), to_string(v[0]),
                      [&](const string &str, int value) {
                          return str + "," + to_string(value);
                      });
}

bool isDone(vector<int> v) {
    return all_of(v.begin(), v.end(), [](int value) { return value <= 0; });
}

void go(vector<int> v, int cnt) {
    if (isDone(v)) {
        ret = min(ret, cnt);
        return;
    }

    string key = createKey(v);
    if (memo.find(key) != memo.end() && memo[key] <= cnt) {
        return;
    }

    memo[key] = cnt;

    vector<int> damages = {1, 3, 9};
    do {
        vector<int> tmp(v);
        int d_idx = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] <= 0) continue;
            tmp[i] -= damages[d_idx];
            d_idx++;
        }
        go(tmp, cnt + 1);
    } while (next_permutation(damages.begin(), damages.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    scv.resize(n);
    for (int i = 0; i < n; i++) cin >> scv[i];

    go(scv, 0);
    cout << ret;
}