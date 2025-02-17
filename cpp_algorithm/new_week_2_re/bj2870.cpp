#include <bits/stdc++.h>

using namespace std;

int n;
string s, snum;
vector<vector<char>> char_cont;
vector<string> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        char_cont.clear();

        // 문자열 내 숫자 추출
        for (char c : s) {
            if (char_cont.empty()) char_cont.push_back(vector<char>());
            auto last_child = (char_cont.end() - 1);
            if ('a' <= c && c <= 'z') {
                if (!(*last_child).empty()) char_cont.push_back(vector<char>());
                continue;
            }

            (*last_child).push_back(c);
        }

        // 숫자의 접두사가 0으로 이뤄져 있는 경우 처리
        for (vector<char> child : char_cont) {
            if (child.empty()) continue;
            snum = string(child.begin(), child.end());
            size_t pos = snum.find_first_not_of('0');
            if (pos != string::npos) {
                snum = snum.substr(pos, snum.size());
            } else {
                snum = "0";
            }
            answer.push_back(snum);
        }
    }

    // 숫자 문자열은 크기가 크기 때문에 문자열로 정렬
    sort(answer.begin(), answer.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for (string snum : answer) cout << snum << "\n";
}