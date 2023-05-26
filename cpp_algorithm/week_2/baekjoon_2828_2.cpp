#include <bits/stdc++.h>

using namespace std;

int n, m, j, l, r, cnt, input;

int main() {
    cin >> n >> m >> j;
    int cnt = 0;
    l = 1;
    for (int i = 0; i < j; i++) {
        r = l + m - 1;
        cin >> input;
        if (l <= input && input <= r)
            continue;
        else {
            // 우측으로 이동
            if (r < input) {
                cnt += (input - r);
                l += (input - r);
            }
            // 좌측으로 이동
            else {
                cnt += (l - input);
                l = input;
            }
        }
    }
    cout << cnt;
}