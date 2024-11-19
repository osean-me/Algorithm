#include <bits/stdc++.h>

using namespace std;

int main() {
    int totalPlayer;                      // 총 선수 수
    int lastNameArr['z' - 'a' + 1] = {};  // 선수의 성 배열
    string result;                        // 출력할 결과
    cin >> totalPlayer;

    // 선수 이름 입력받고 카운트
    for (int i = 0; i < totalPlayer; i++) {
        string fullName;
        cin >> fullName;
        char lastName = fullName.substr(0, 1)[0];
        lastNameArr[lastName - 'a']++;
    }

    // 동일한 성 5개 이상인 성 체크
    for (int i = 'a'; i <= 'z'; i++) {
        if (lastNameArr[i - 'a'] >= 5) {
            result += i;
        }
    }

    // 결과 출력
    if (result.size())
        cout << result;
    else
        cout << "PREDAJA";

    return 0;
}