//
// Created by SeongHeon Sim on 2023/04/19.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x, y, z = 0L;

ll go(ll x, ll y) {
    if (y == 1) return x % z;
    ll result = go(x, y / 2);
    result = (result * result) % z;
    if (y % 2) result = (result * x) % z;
    return result;
}

int main() {
    cin >> x >> y >> z;
    cout << go(x, y);
}
