#include <bits/stdc++.h>

using namespace std;

int n, m, j;
int arr[20];

int main() {
    cin >> n >> m >> j;
    for (int i = 0; i < j; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    int current = m - 1;
    int cnt = 0;
    for (int i = 0; i < j; i++) {
        if (current <= arr[i]) {
            for (int k = current; k < arr[i]; k++) cnt++;
            if (current != (arr[i] + 1)) current = arr[i];
        } else {
            for (int k = (current - m + 1); k > arr[i]; k--) cnt++;
            if (current != (arr[i] + 1)) current = arr[i] + m - 1;
        }
        cout << cnt << " : " << current << "\n";
    }
    cout << cnt;
}