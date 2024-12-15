#include <bits/stdc++.h>

using namespace std;

string input;
vector<int> vec(26, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::toupper);

    for (char c : input) {
        vec[c - 'A']++;
    }

    // 단어 내에서 가장 많은 빈도로 사용된 알파벳 추출
    auto max_frequency = max_element(vec.begin(), vec.end());
    int count_max = count(vec.begin(), vec.end(), *max_frequency);

    // 첫 번째와 두 번째가 같으면 같은 빈도수의 알파벳이 여러 개 있다는 의미
    if (count_max > 1) {
        cout << "?";
    } else {
        int max_index = distance(vec.begin(), max_frequency);
        cout << (char)('A' + max_index);
    }
}