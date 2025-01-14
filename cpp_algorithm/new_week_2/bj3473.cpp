#include <bits/stdc++.h>

using namespace std;

int n;
long long num;

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;

        long long cnt = 0;
        for (int i = 5; i <= num; i *= 5) {
            cnt += (num / i);
        }
        cout << cnt << "\n";
    }
}