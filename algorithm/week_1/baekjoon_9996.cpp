//
// Created by SeongHeon Sim on 2023/04/03.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int cnt, idx;
string pattern;
string startPattern, endPattern;
vector<string> result;

void find() {
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '*') {
            idx = i;
            return;
        }
    }
}

int main() {
    cin >> cnt;
    cin >> pattern;
    find();
    for (int i = 0; i < idx; i++) startPattern += pattern[i];
    for (int i = idx + 1; i < pattern.length(); i++) endPattern += pattern[i];
    for (int i = 0; i < cnt; i++) {
        string input;
        cin >> input;
        string start;
        for (int j = 0; j < idx; j++) start += input[j];
        string end;
        for (int k = input.length() - idx; k < input.length(); k++) end += input[k];
        if ((start == startPattern) && (end == endPattern)) {
            result.push_back("DA");
        } else {
            result.push_back("NE");
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << "\n";
    }
}
