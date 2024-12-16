#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;

bool isPrimary(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    // 주어진 수의 제곱근 찾기
    int limit = sqrt(x);
    // 3부터 제곱근까지 2씩 커지기
    // x까지 모든 값을 순회도는 것은 비효율적
    // 짝수는 위에서 정리했으니, 해당 반복문에서는 홀수에 대한 처리만 한다.
    for (int i = 3; i < limit; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }
}