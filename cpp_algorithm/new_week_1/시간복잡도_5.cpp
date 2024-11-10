#include <bits/stdc++.h>

using namespace std;

int N;
int cnt;

// 시간 복잡도 : 1 * ((3^n+1) - 1) / (3 - 1)
// BigO : O(3^n)
void solve(int N) {
    cnt++;
    cout << cnt << '\n';
    if (N == 0) return;
    for (int i = 0; i < 3; i++) {
        solve(N - 1);
    }
    return;
}

int main() {
    cin >> N;
    solve(N);
    return 0;
}