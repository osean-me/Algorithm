#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int n;
        cin >> n;
        unordered_map<string, long long> categories = {};

        for (int i = 0; i < n; i++) {
            string clothe, category;
            cin >> clothe >> category;
            categories[category]++;
        }

        long long result = 1;
        for (auto it : categories) {
            // 1을 더하는 이유는 해당 카테고리 옷을 선택하지 않는 경우를
            // 포함하기 위해서
            result *= it.second + 1;
        }
        // 마지막에 하나를 빼는 이유는?
        // 아무 것도 안입는 경우를 제외하기 위해서
        result--;
        cout << result << "\n";
    };
}