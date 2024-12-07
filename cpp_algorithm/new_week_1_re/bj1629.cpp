#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll n, ll m, ll k) {
    if (m == 0) {
        return 1;
    }

    ll tmp = solve(n, m / 2, k);
    ll result = (tmp * tmp) % k;
    if (m % 2 == 1) result = (result * n) % k;
    return result;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}