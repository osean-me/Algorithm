#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

bool check(int sum) {
    if (sum < 2) return 0;
    if (sum == 2) return 1;
    if (sum % 2 == 0) return 0;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) return 0;
    }

    return 1;
}

int go(int i, int sum) {
    if (i == n) return check(sum);
    return go(i + 1, sum + v[i]) + go(i + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    cout << go(0, 0);
}