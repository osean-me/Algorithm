#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t, n, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 5; j <= n; j *= 5) {
            cnt += (n / j);
        }
        cout << cnt << "\n";
        cnt = 0;
    }
}