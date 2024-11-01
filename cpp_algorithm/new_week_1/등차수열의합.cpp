#include <bits/stdc++.h>

using namespace std;

void arithmetic(vector<int> &v, int a, int r, int n) {
    if (v.size() == n) {
        for (int value : v) cout << value << " ";
        cout << "\n";
        return;
    }

    if (v.size() == 0) {
        v.push_back(a);
    } else {
        v.push_back(v.back() + r);
    }

    arithmetic(v, a, r, n);
}

int main() {
    // a = 초항
    // d = 공차
    // n = 위치
    // l = a 에서 n 까지 d 만큼 이동한 수
    int a, d, n, l;
    cin >> a >> d >> n;
    l = a + (n - 1) * d;

    cout << "a : " << a << ", d : " << d << ", n : " << n << ", l : " << l
         << "\n";

    // 등차수열의 합 구하기
    int result = n * (a + l) / 2;
    cout << result << "\n";

    // 등차수열 만들기
    vector<int> v;
    arithmetic(v, a, d, n);

    return 0;
}