//
// Created by SeongHeon Sim on 2023/03/14.
//
#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159
#define loop(x, n) for(int x = 0; x < n; x++)

int main() {
    // PI 출력
    cout << PI << '\n';

    // 반복문 수행
    int sum = 0;

    // 입력
    int a;
    cin >> a;

    loop(i, a) {
        cout << i << '\n';
        sum += i;
    }
    cout << sum << '\n';

    return 0;
}