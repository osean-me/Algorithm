#include <bits/stdc++.h>

using namespace std;

int n, ret, cnt;
vector<int> v;

void go(int i, int sum) {
    if (ret == 10) return;
    if (i == n) {
        cnt++;
        ret = max(ret, (sum % 11));
        return;
    }
    go(i + 1, sum + v[i]);
    go(i + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    go(0, 0);
    cout << ret << "\n" << cnt;
}