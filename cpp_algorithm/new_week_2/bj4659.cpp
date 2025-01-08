#include <bits/stdc++.h>

using namespace std;

string s;
int vowelCnt = 0;
bool isAcceptable = true;
vector<char> threeInRow, twoInRow;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool checkThreeInRow(char c, bool currentIsVowel) {
    if (!threeInRow.empty()) {
        bool beforeIsVowel = isVowel(*(threeInRow.end() - 1));

        if (beforeIsVowel != currentIsVowel) threeInRow.clear();
    }

    threeInRow.push_back(c);

    return threeInRow.size() == 3;
}

bool checkTwoInRow(char c) {
    if (!twoInRow.empty()) {
        bool isEqual = c == *(twoInRow.end() - 1);

        if (!isEqual) twoInRow.clear();
    }
    twoInRow.push_back(c);

    return twoInRow.size() == 2 && c != 'e' && c != 'o';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        if (s == "end") {
            break;
        }

        for (auto it = s.begin(); it < s.end(); it++) {
            char c = *it;

            bool currentIsVowel = isVowel(c);
            if (currentIsVowel) vowelCnt++;

            if (checkThreeInRow(c, currentIsVowel) || checkTwoInRow(c)) {
                isAcceptable = false;
                break;
            }
        }

        if (vowelCnt == 0) {
            isAcceptable = false;
        }

        if (isAcceptable) {
            cout << "<" << s << "> is acceptable.\n";
        } else {
            cout << "<" << s << "> is not acceptable.\n";
        }

        isAcceptable = true;
        vowelCnt = 0;
        threeInRow.clear();
        twoInRow.clear();
    }
}