#include <bits/stdc++.h>

using namespace std;

int n;
char adj[70][70];

string go(int y, int x, int size) {
    char c = adj[y][x];
    string result = "";
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (c != adj[i][j]) {
                int next = size / 2;
                result += "(";
                result += go(y, x, next);                // 좌상
                result += go(y, x + next, next);         // 우상
                result += go(y + next, x, next);         // 좌하
                result += go(y + next, x + next, next);  // 우하
                result += ")";
                return result;
            }
        }
    }
    return string(1, adj[y][x]);
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        string input = "";
        cin >> input;
        for (int x = 0; x < n; x++) adj[y][x] = input[x];
    }

    cout << go(0, 0, n);
}