#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x1, y1, x2, y2, psum[1025][1025] = {};
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> psum[i][j];
            psum[i][j] += psum[i][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for (int i = x1; i <= x2; i++) {
            result += (psum[i][y2] - psum[i][y1 - 1]);
        }
        cout << result << "\n";
    }
}