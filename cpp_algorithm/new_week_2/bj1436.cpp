#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int i = 666;
    /**
     * 1. 666가 가장 작은 값이니, 666부터 시작
     * 2. i 의 값을 1 씩 늘려가면서 현재 i에 "666"이 포함되어 있는지 확인
     * 3. 포함되어 있다면 n-- 수행 > 발견할 때 마다 조건과 순서에 맞기 때문
     * 4. n 이 0 인 경우는?
     *      > i를 1씩 늘리면서 "666"이 포함된 n번째 순서의 숫자를 찾았다는 의미
     */
    for (;; i++) {
        if (to_string(i).find("666") != string::npos) {
            cout << i << "\n";
            n--;
        }
        if (n == 0) break;
    }
    cout << i;
}