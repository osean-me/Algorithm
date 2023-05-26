//
// Created by SeongHeon Sim on 2023/04/18.
//
#include <bits/stdc++.h>

using namespace std;

int n, m = 0;
int arr[15010] = {};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (200000 <= m) cout << 0;
    else {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == m) cnt++;
            }
        }
        cout << cnt;
    }
}
