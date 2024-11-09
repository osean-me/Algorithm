#include <bits/stdc++.h>

using namespace std;

void geometric(vector<int> &v, int a, int r, int n) {
    // 벡터의 길이가 n과 같다면 리턴
    if (v.size() == n) {
        for (int value : v) cout << value << " ";
        cout << "\n";
        return;
    }

    // 현재 벡터에 아무것도 존재하지 않는다면 최초 a의 값을 push한다.
    if (v.size() == 0) {
        v.push_back(a);
    } else {
        a = v.back() * r;
        v.push_back(a);
    }

    geometric(v, a, r, n);
}

/**
 * 등비수열?
 * - 각 항이 일정한 비율로 증가하거나 감소하는 수열
 * - a = 초항
 * - r = 공차(각 항이 이전 항에 곱해지는 일정한 값)
 * - 재귀적 표현
 *  - an = a * (n - 1) * r
 * - 일반적 표현
 *  - an = a * r 의 n - 1 제곱
 */
int main() {
    int a, r, n;
    // 일단 등비수열을 만들어볼까?
    cin >> a >> r >> n;
    vector<int> v;
    geometric(v, a, r, n);

    // 등비수열의 합을 구해보자
    // a(r의 n제곱 - 1) / (r - 1)
    // pow() ? 거듭제곱을 하는 함수
    cout << a * (pow(r, n) - 1) / (r - 1) << " = ";
    int result = 0;
    for (int value : v) result += value;
    cout << result;

    return 0;
}