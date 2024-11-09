#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &v) {
    for (int value : v) cout << value << " ";
    cout << "\n";
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

/**
 * rotate() 함수를 구현할 때 최대공약수(GCD) 를 사용하는 이유?
 * 1. 사이클 수 최소화를 위해서
 * 2. 사이클 길이를 결정
 * 3. 효율적인 교환
 * 4. 시간 복잡도 감소
 */
template <typename Iterator>
Iterator rotate_copy(Iterator start, Iterator middle, Iterator end) {
    if (start == middle || end == middle) return middle;

    auto n = end - start;
    auto k = middle - start;
    auto gcd_value = gcd(n, k);

    for (int i = 0; i < gcd_value; ++i) {
        auto temp = *start;
        auto current = start;

        while (true) {
            auto next = current + k;

            if (next >= end) next -= n;
            if (next == start) break;

            *current = *next;
            current = next;
        }

        *current = temp;
        ++start;
    }

    return start + (end - middle);
}

int main() {
    vector<int> v = {1, 2, 4, 8, 16, 32, 64};
    // 반시계 방향으로 1칸 씩
    rotate(v.begin(), v.begin() + 1, v.end());
    print(v);

    // 반시계 방향으로 2칸 씩
    rotate(v.begin(), v.begin() + 2, v.end());
    print(v);

    // 시계 방향으로 3칸 씩
    rotate(v.rbegin(), v.rbegin() + 3, v.rend());
    print(v);

    // 1 ~ 5까지 반시계 방향으로 1칸 씩
    rotate(v.begin() + 1, v.begin() + 2, v.begin() + 6);
    print(v);

    // 1 ~ 5까지 시계방향으로 1칸 씩
    rotate(v.rbegin() + 1, v.rbegin() + 2, v.rbegin() + 6);
    print(v);

    // GCD(최대공약수) 를 이용해 rotate() 함수 구현하기
    rotate_copy(v.begin(), v.begin() + 1, v.end());
    print(v);

    return 0;
}