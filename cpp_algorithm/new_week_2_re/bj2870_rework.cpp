#include <bits/stdc++.h>

using namespace std;

int n;
string s, nstr;
vector<vector<char>> charsList;
vector<string> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;

        charsList.push_back(vector<char>());

        for (char c : s) {
            vector<char> &lastChars = charsList.back();

            if ('a' <= c && c <= 'z') {
                if (!lastChars.empty()) charsList.push_back(vector<char>());
                continue;
            }

            lastChars.push_back(c);
        }
    }

    for (vector<char> chars : charsList) {
        if (chars.empty()) continue;
        nstr = string(chars.begin(), chars.end());
        size_t pos = nstr.find_first_not_of('0');
        if (pos != string::npos) {
            nstr = nstr.substr(pos, nstr.size());
        } else {
            nstr = "0";
        }
        answer.push_back(nstr);
    }

    sort(answer.begin(), answer.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a[0] < b[0];
        return a.size() < b.size();
    });

    for (string str : answer) cout << str << "\n";
}