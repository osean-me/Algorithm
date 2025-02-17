#include <bits/stdc++.h>

using namespace std;

string s;
int vowelCnt;
bool flag, isVowel;
vector<char> threeCharsContainer, twoCharsContainer;

void print(bool f) {
    cout << "<" << s << "> ";
    if (f) {
        cout << "is not acceptable.\n";
    } else {
        cout << "is acceptable.\n";
    }
}

bool validVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool validThreeChars(char c, bool isVowel) {
    if (!threeCharsContainer.empty()) {
        bool isLastCharVowel = validVowel(*(threeCharsContainer.end() - 1));
        if (isVowel != isLastCharVowel) threeCharsContainer.clear();
    }
    threeCharsContainer.push_back(c);
    return threeCharsContainer.size() == 3;
}

bool validTwoChars(char c) {
    if (!twoCharsContainer.empty()) {
        char lastChar = *(twoCharsContainer.end() - 1);
        if (c != lastChar) twoCharsContainer.clear();
    }
    twoCharsContainer.push_back(c);
    return twoCharsContainer.size() == 2 && c != 'e' && c != 'o';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> s) {
        if (s == "end") break;

        flag = false;
        vowelCnt = 0;
        twoCharsContainer.clear();
        threeCharsContainer.clear();

        for (char c : s) {
            isVowel = validVowel(c);
            if (isVowel) vowelCnt++;

            if (validThreeChars(c, isVowel) || validTwoChars(c)) {
                flag = true;
                break;
            }
        }

        print(!vowelCnt || flag);
    }
}