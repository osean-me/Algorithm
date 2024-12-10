#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, psum[1025][1025] = {};
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int input;
            cin >> input;
            /**
             * x x x
             * ------
             * 4 3 x
             * ------
             * 2 1 x
             * ------
             * 1 = 현재 입력값 + 2 + 3 - 4
             */
            psum[i][j] =
                input + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] +
                    psum[x1 - 1][y1 - 1]
             << "\n";
    }
}