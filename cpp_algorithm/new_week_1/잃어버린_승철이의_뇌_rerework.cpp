#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> psum(100001, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;

        cout << psum[end] - psum[start - 1] << "\n";
    }
}