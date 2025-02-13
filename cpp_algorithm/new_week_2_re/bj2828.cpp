#include <bits/stdc++.h>

using namespace std;

int n, m, q, p, s, e, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;
    s = 0;
    e = m - 1;

    for (int i = 0; i < q; i++) {
        cin >> p;
        p -= 1;
        // 바구니 안으로 떨어지는 경우
        if (s <= p && p <= e) {
            continue;
        }
        // 바구니 왼쪽으로 떨어지는 경
        if (e < p) {
            cnt += (p - e);
            e = p;
            s = (e - m + 1);
        }
        // 바구니 오른쪽으로 떨어지는 경우
        if (p < s) {
            cnt += (s - p);
            s = p;
            e = (s + m - 1);
        }
    }
    cout << cnt;
}