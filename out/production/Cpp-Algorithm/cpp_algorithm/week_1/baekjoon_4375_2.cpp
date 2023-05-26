//
// Created by SeongHeon Sim on 2023/04/23.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        ll cnt = 1L, plus = 10L, r = 1L;
        while (cnt % n != 0) {
            cout << "cnt : " << cnt << "\n";
            cnt += plus;
            plus *= 10;
            r++;
        }
    }
}
