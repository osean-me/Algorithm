#include <bits/stdc++.h>

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int x = 0, y = 0;
    // 반드시 4방향이 아닐 수 있다.
    // 문제에 따라 방향은 달라질 수 있으니 주의할 것. (늘 시계방향 X)
    for (int i = 0; i < 8; i++) {
        cout << (y + dy[i]) << " : " << (x + dx[i]) << "\n";
    }
}