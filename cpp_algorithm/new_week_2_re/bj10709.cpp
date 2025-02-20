#include <bits/stdc++.h>

using namespace std;

int h, w;
string s;
vector<vector<int>> adj(101, vector<int>(101, -1));

void go(int y, int x) {
    for (int nx = x + 1; nx < w; nx++) {
        if (!adj[y][nx]) return;
        adj[y][nx] = adj[y][nx - 1] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == 'c') adj[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (adj[i][j] == 0) go(i, j);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << adj[i][j] << " ";
        cout << "\n";
    }
}