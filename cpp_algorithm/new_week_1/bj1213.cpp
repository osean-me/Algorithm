#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    int arr[26] = {};
    int oddCnt = 0;
    string result, odd = "";

    for (char c : input) arr[c - 'A']++;

    for (char c = 'A'; c <= 'Z'; c++) {
        int index = c - 'A';
        int total = arr[index];

        if (total == 0) {
            continue;
        }

        // 홀수인 경우 가운데에 한자리 차지해야 한다.
        if (total % 2 != 0) {
            oddCnt++;
            odd = c;
        }

        // 개수가 홀수인 알파벳이 2개 이상이면 팰린드롬 불가
        if (oddCnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }

        // 전체 문자열의 반만 설정한다.
        for (int i = 0; i < total / 2; i++) {
            result += c;
        }
    }

    cout << (result + odd);
    reverse(result.begin(), result.end());
    cout << result;
}