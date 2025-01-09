#include <bits/stdc++.h>

using namespace std;

string s;
int vcnt, ccnt;

bool validateVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> s) {
        if (s == "end") break;
        vcnt = ccnt = 0;
        bool acceptable = true, includable = false;
        int prev = -1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (validateVowel(c)) {
                vcnt++;
                includable = true;
                ccnt = 0;
            } else {
                ccnt++;
                vcnt = 0;
            }

            if (vcnt == 3 || ccnt == 3) acceptable = false;
            if (1 <= i && c == prev && c != 'e' && c != 'o') acceptable = false;
            prev = c;
        }

        if (!includable) acceptable = false;
        if (acceptable) {
            cout << "<" << s << "> is acceptable.\n";
        } else {
            cout << "<" << s << "> is not acceptable.\n";
        }
    }
}