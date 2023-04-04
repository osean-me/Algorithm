//
// Created by SeongHeon Sim on 2023/04/03.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int cnt, idx;
string pattern;
vector<string> result;

void newPattern() {
    string newPattern;
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '*') idx = i;
        else newPattern += pattern[i];
    }
    pattern = newPattern;
}

string split(string basicString) {
    string tmp;
    string str;
    int length = basicString.length();
    for (int i = 0; i < idx; i++) tmp += basicString[i];
    for (int i = length - idx; i < length; i++) tmp += basicString[i];
    for (int i = 0; i < length; i++) str += tmp[i];
    return str;
}

int main() {
    cin >> cnt;
    cin >> pattern;
    newPattern();
    for (int i = 0; i < cnt; i++) {
        string input;
        cin >> input;
        string sResult = split(input);
        cout << input << " / " << sResult << " / " << pattern << "\n";
        if (sResult == pattern) result.push_back("DA");
        else result.push_back("NE");
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i <= result.size() - 1) cout << "\n";
    }
}
