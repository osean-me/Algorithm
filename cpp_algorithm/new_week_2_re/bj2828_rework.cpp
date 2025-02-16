#include <bits/stdc++.h>

using namespace std;

int n, m, j, k, s, e, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> j;

    s = 0;
    e = m - 1;

    for (int i = 0; i < j; i++) {
        cin >> k;
        k -= 1;

        // 바구니 안으로 떨어지는 경우
        if (s <= k && k <= e) continue;
        // 바구니 왼쪽 바깥으로 떨어지는 경우
        if (e < k) {
            c += (k - e);
            e = k;
            s = (e - m + 1);
        }
        // 바구니 오른쪽 바깥으로 떨어지는 경우
        if (k < s) {
            c += (s - k);
            s = k;
            e = (s + m - 1);
        }
    }

    cout << c;
}