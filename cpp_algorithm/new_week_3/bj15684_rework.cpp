#include <bits/stdc++.h>

using namespace std;

int n, m, h, ret = INT_MAX;
int board[34][34];

bool validate() {
    for (int i = 1; i <= n; i++) {
        int start = i;

        for (int j = 1; j <= h; j++) {
            if (board[j][start]) {
                start++;
            } else if (board[j][start - 1]) {
                start--;
            }
        }

        if (start != i) return false;
    }
    return true;
}

void go(int here, int cnt) {
    if (cnt > 3 || cnt >= ret) return;
    if (validate()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i <= h; i++) {
        for (int j = 1; j < n; j++) {
            if (board[i][j] || board[i][j - 1] || board[i][j + 1]) continue;
            board[i][j] = 1;
            go(i, cnt + 1);
            board[i][j] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    go(1, 0);

    cout << (ret == INT_MAX ? -1 : ret);
}