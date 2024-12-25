#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0 - 1};

int main() {
    int x = 0, y = 0;
    for (int i = 0; i < 4; i++) {
        cout << (y + dy[i]) << " : " << (x + dx[i]) << "\n";
    }
}