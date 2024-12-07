#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, cnt = 0L;
    cin >> n >> m;

    vector<bool> flags(10000001, false);
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        flags[numbers[i]] = true;
    }

    for (int number : numbers) {
        int pairNumber = m - number;

        // pairNumber 가 음수인 경우는 number + pairNumber2 = m 조건 X
        // 갑옷 재료는 자연수 고유의 값. 음수가 올 수 없다.
        if (pairNumber < 0) continue;
        // number 와 pairNumber 가 같은 경우는 재료가 하나 밖에 없다는 것
        if (number == pairNumber) continue;
        if (!flags[pairNumber]) continue;

        cnt++;
        flags[number] = false;
        flags[pairNumber] = false;
    }

    cout << cnt;
}