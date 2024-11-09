#include <bits/stdc++.h>

using namespace std;

int n, a[1004], cnt;

int go(int l, int r) {
    cnt++;
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    int sum = go(l, mid) + go(mid + 1, r);
    return sum;
}

// 시간 복잡도 : 2n - 1
// n : 5, cnt : 9
// n : 10, cnt : 19
// n : 15, cnt : 29
// n : 20, cnt : 39
// 어라라? cnt = 2n - 1
// BigO : O(n)
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }
    int sum = go(0, n - 1);
    cout << sum << '\n';
    cout << cnt << '\n';
}