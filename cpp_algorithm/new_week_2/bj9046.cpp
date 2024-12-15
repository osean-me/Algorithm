#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);

        vector<int> frequency(26, 0);
        for (char c : input) {
            if ('a' <= c && c <= 'z') frequency[c - 'a']++;
        }

        auto max_frequency = max_element(frequency.begin(), frequency.end());
        int max_count =
            count(frequency.begin(), frequency.end(), *max_frequency);

        if (1 < max_count) {
            result.push_back("?");
        } else {
            int max_index = distance(frequency.begin(), max_frequency);
            result.push_back(string(1, 'a' + max_index));
        }
    }

    for (string str : result) cout << str << "\n";
}