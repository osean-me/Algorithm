//
// Created by SeongHeon Sim on 2023/04/17.
//
#include <bits/stdc++.h>

using namespace std;

long long n, m = 0;
long long arr[100010] = {};

int main() {
    cin >> n >> m;
    vector<int> idx = vector<int>();
    for (int i = 0; i < n; i++) {
        int index = 0;
        cin >> index;
        arr[index]++;
        idx.push_back(index);
    }
    long long let = 0;
    for (int i = 0; i < n; i++) {
        int index = idx[i];
        if (arr[index] == 0) continue;
        long long second = m - index;
        if (index != second && arr[second] > 0) {
            let++;
            arr[second] = 0;
        }
    }
    cout << let;
}
