#include <bits/stdc++.h>

using namespace std;

int n, m, j, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> j;

    int start = 1, end = m, move = 0;
    for (int i = 0; i < j; i++) {
        cin >> p;

        if (p < start) {
            move += (start - p);
            start = p;
            end = p + m - 1;
        }

        if (end < p) {
            move += (p - end);
            start = (p - m + 1);
            end = p;
        }
    }
    cout << move;
}