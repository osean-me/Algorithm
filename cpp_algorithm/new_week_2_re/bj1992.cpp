#include <bits/stdc++.h>

using namespace std;

int n;
int adj[65][65] = {};
string s;

string go(int y, int x, int d) {
    if (d == 1) return to_string(adj[y][x]);
    for (int ny = y; ny < y + d; ny++) {
        for (int nx = x; nx < x + d; nx++) {
            if (adj[y][x] != adj[ny][nx]) {
                int next_d = d / 2;
                return "(" + go(y, x, next_d) + go(y, x + next_d, next_d) +
                       go(y + next_d, x, next_d) +
                       go(y + next_d, x + next_d, next_d) + ")";
            }
        }
    }
    return to_string(adj[y][x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) adj[i][j] = s[j] - '0';
    }

    cout << go(0, 0, n);
}