#include <bits/stdc++.h>

using namespace std;

int n, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;

    vector<int> numbers(n);
    unordered_map<int, pair<int, int>>
        freqMap;  // {number: {frequency, first_index}}

    // 입력 처리
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (freqMap.find(numbers[i]) == freqMap.end()) {
            freqMap[numbers[i]] = {1, i};  // 첫 등장
        } else {
            freqMap[numbers[i]].first++;  // 빈도 증가
        }
    }

    // 정렬
    sort(numbers.begin(), numbers.end(), [&](int a, int b) {
        if (freqMap[a].first == freqMap[b].first) {
            // 먼저 등장한 순서대로
            return freqMap[a].second < freqMap[b].second;
        }
        return freqMap[a].first > freqMap[b].first;  // 빈도 내림차순
    });

    // 출력
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << "\n";

    return 0;
}