//
// Created by SeongHeon Sim on 2023/04/23.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        ll cnt = 1L, r = 1L;
        while (cnt % n != 0) {
            cnt = (cnt % n) * 10 + 1;
            r++;
        }
        cout << r << "\n";
    }
    return 0;
}
