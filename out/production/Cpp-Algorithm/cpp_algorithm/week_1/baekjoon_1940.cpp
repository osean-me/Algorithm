//
// Created by SeongHeon Sim on 2023/04/17.
//
#include <bits/stdc++.h>

using namespace std;

long long n, m, cnt = 0L;
long long arr[10000010] = {};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long input = 0L;
        cin >> input;
        arr[input]++;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        long r = m - i;
        if (r < 0) continue;
        if (arr[i] == 0 || arr[r] == 0) continue;
        if (i == r) continue;
        arr[i] = 0;
        arr[r] = 0;
        cnt++;
    }
    cout << cnt;
}
