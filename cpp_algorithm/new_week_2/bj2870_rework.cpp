#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> nums;

bool validateNum(char c) { return '0' <= c && c <= '9'; }

string removeZero(string str) {
    size_t size = str.find_first_not_of('0');
    if (size == string::npos) {
        return "0";
    }

    return str.substr(size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (!validateNum(s[i])) continue;
            string tmp;
            for (int j = i; j < s.size(); j++) {
                if (!validateNum(s[j])) {
                    i = j;
                    break;
                }

                if (j == s.size() - 1) i = j;
                tmp += s[j];
            }
            nums.push_back(removeZero(tmp));
        }
    }

    sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    for (string num : nums) cout << num << "\n";
}