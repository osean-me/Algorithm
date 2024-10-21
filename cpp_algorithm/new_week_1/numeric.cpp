#include <bits/stdc++.h>

using namespace std;

int main() {
    // int, 4bytes 정수
    int a = 10;
    // 문제를 풀 때 최대값으로 보통 아래의 값을 사용한다.
    // dhosiaus INF 와 INF 간 연산이 존재할 수 있기 때문이다.
    const int INF = 987654321;
    const int INF2 = 1e9;

    // int 연산
    // int 로 선언한 변수끼리 연산한 결과가 실수면 소수점 아래의 수는 버림한다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int b = 3;
    int c = 2;
    cout << a / b << '\n';  // 1
    // double 의 경우 버림없이 처리한다.
    double d = 3;
    double e = 2;
    cout << d / e << '\n';  // 1.5
    return 0;
}