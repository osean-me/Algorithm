#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MAX;
vector<int> scvs;
unordered_map<string, int> memo;

bool isDone(const vector<int>& v) {
    return all_of(v.begin(), v.end(), [](int value) { return value <= 0; });
}

string vectorToString(const vector<int>& v) {
    string s;
    for (int i : v) {
        s += to_string(i) + ",";
    }
    return s;
}

void go(vector<int> v, int cnt) {
    if (isDone(v)) {
        ret = min(ret, cnt);
        return;
    }

    // 현재 상태를 문자열로 변환하여 이미 계산한 적 있는 상태인지 확인
    string key = vectorToString(v);
    if (memo.find(key) != memo.end() && memo[key] <= cnt) {
        return;  // 이미 더 적은 횟수로 처리된 상태가 있으면 돌아가
    }

    // 메모에 현재 상태와 횟수를 저장
    memo[key] = cnt;

    vector<int> damages = {1, 3, 9};
    do {
        vector<int> tmp_v(v);
        int d_idx = 0;
        for (int i = 0; i < tmp_v.size(); i++) {
            if (tmp_v[i] <= 0) continue;
            tmp_v[i] -= damages[d_idx];
            d_idx++;
        }
        go(tmp_v, cnt + 1);
    } while (next_permutation(damages.begin(), damages.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    scvs.resize(n);
    for (int i = 0; i < n; i++) cin >> scvs[i];

    go(scvs, 0);

    cout << ret;
}