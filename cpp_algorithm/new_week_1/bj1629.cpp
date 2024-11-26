#include <bits/stdc++.h>

using namespace std;

int go(long long a, long long b, long long c) {
    // 모듈러 연산의 마지막 조건
    if (b == 1) return a % c;

    // 제곱근의 절반씩 줄여나간다.
    long long tmp = go(a, b / 2, c);
    // 모듈러 연산 곱셈 기질
    // (a * b) % c = (a % c) * (b * c) % c
    // 위 공식에서 (a % c) 혹은 (b * c) 는 재귀함수의 기저사례!
    tmp = (tmp * tmp) % c;
    // 제곱근의 값이 홀수인 경우
    // a 를 한 번 더 곱하도록 한다. ex) 2^3 = 2^2 * 2
    if (b % 2) tmp = (tmp * a) % c;
    return tmp;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << go(a, b, c);
}