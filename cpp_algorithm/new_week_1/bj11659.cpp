#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, arr[100001] = {};
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << "\n";
    }
}