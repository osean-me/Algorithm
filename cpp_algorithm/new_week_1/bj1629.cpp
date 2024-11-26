#include <bits/stdc++.h>

using namespace std;

int go(long long a, long long b, long long c) {
    if (b == 1) return a % c;

    long long tmp = go(a, b / 2, c);
    tmp = tmp * tmp % c;
    if (b % 2) tmp = (tmp * a) % c;
    return tmp;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << go(a, b, c);
}