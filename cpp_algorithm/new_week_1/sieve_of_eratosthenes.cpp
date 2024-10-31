#include <bits/stdc++.h>

using namespace std;

/**
 * 에라토스테네스의 체?
 * - 소수가 아닌 값들에 대한 불리언 배열을 만들어 소수만 걸러낼 수 있는 방법
 */
bool check(int n) {
    // 1보다 같거나 작으면 소수가 아니다
    if (n <= 1) return 0;
    // 2는 소수다.
    if (n == 2) return 1;
    // 2의 배수는 소수가 아니다.
    if (n % 2 == 0) return 0;
    // 3의 배수는 소수가 아니다.
    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

// 예를 들어 40을 넣었을 때 che[40] 이 참조가 되니, max_n + 1 을 넣어야 함.
// max_n 개 까지의 소수를 만드는 함수
const int max_n = 40;
bool che[max_n + 1];

vector<int> fun_1(vector<int> &v) {
    // 0과 1은 소수가 아니므로 제외
    // 2부터 시작하여 마지막까지 순회돈다.
    for (int i = 2; i <= v.size(); i++) {
        // c++ 에서 1 = true 이기 때문에
        // 소수가 아닌 자연수는 다음 반복문으로 이동하도록 한다.
        if (v[i]) continue;
        // 소수부터 마지막 수까지 순회를 돌면서
        // 현재 소수의 배수에 플래그를 세운다.
        for (int j = i * 2; j <= v.size(); j += i) {
            v[j] = 1;
        }
    }

    vector<int> result;
    // 2부터 마지막까지 순회를 돌면서 각 인덱스에 설정된 플래그가 false 인
    // 인덱스를 결과 벡터에 담는다.
    for (int i = 2; i <= v.size(); i++) {
        if (v[i] == 0) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    vector<int> v(40);
    vector<int> result = fun_1(v);
    for (int value : result) cout << value << " ";
    cout << "\n";

    for (int i = 2; i < v.size(); i++) {
        if (check(i)) {
            cout << i << "는 소수입니다.\n";
        }
    }
    return 0;
}