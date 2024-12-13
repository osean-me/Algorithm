#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<double> psum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }

    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n" << fixed << setprecision(2) << psum.back() / n;
}