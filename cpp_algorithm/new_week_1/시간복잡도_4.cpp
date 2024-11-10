#include <bits/stdc++.h>

using namespace std;

// 시간 복잡도 : log2N
// BigO : O(logN)
void solve(int N) {
    int a = 0;
    int i = N;
    int cnt = 0;
    while (i > 0) {
        cnt++;
        a += i;
        i /= 2;
    }

    cout << a << '\n';
    cout << cnt << '\n';
}

int main() {
    int N = 0;
    cin >> N;
    solve(N);
    return 0;
}