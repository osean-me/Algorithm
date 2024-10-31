#include <bits/stdc++.h>

using namespace std;

/**
 * 1. b 는 a 보다 커야한다.
 * 2. a 가 0 인 경우는 a 로 b 를 나눈 마지막 경우이고,
 *    이 때의 b 는 두 수의 최대공약수이다.
 */
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    cout << "\n";
    cout << lcm(a, b);
    return 0;
}