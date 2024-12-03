#include <bits/stdc++.h>

using namespace std;

// 카테고리 별 수량을 겹치지 않게 모두 한 번씩 입어보려면
// 모든 카테고리 수량 + 1 을 한 뒤 그 값들을 모두 곱한다.
// 그리고 모두 입지 않은 케이스를 제외해야 하기 때문에 -1 한 번
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        unordered_map<string, int> categoryMap = {};
        for (int i = 0; i < k; i++) {
            string name, category;
            cin >> name >> category;
            categoryMap[category]++;
        }

        int result = 1;
        for (pair<string, int> category : categoryMap) {
            result *= (category.second + 1);
        }
        cout << result - 1 << "\n";
    }
}