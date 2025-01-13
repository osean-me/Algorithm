#include <bits/stdc++.h>

using namespace std;

int h, w;
vector<vector<int>> adj(101, vector<int>(101, -1));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < w; j++) {
            if (s[j] != 'c') continue;
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (adj[i][j] == 0) {
                int cnt = 0;
                for (int l = j; l < w; l++) {
                    if (adj[i][l] == 0) {
                        j = l;
                        cnt = 0;
                        continue;
                    }
                    if (l == w - 1) j = l;
                    adj[i][l] = ++cnt;
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}