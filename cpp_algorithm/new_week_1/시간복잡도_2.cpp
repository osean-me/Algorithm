#include <bits/stdc++.h>

using namespace std;

// 시간 복잡도 : n + m
void solve(int n, int m) {
    int a = 1;
    for (int i = 0; i < n; i++) {
        a *= i;
    }

    for (int j = 0; j < m; j++) {
        a += j;
    }

    cout << a << '\n';
}

// BigO : O(n + m)
int main() {
    int n, m;
    cin >> n >> m;
    solve(n, m);

    return 0;
}