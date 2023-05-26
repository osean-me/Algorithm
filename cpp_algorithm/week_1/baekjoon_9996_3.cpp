//
// Created by SeongHeon Sim on 2023/04/04.
//
#include <bits/stdc++.h>

using namespace std;

int cnt;
string pattern, input;

int main() {
    cin >> cnt;
    cin >> pattern;
    int pos = pattern.find('*');
    string prefix = pattern.substr(0, pos);
    string suffix = pattern.substr(pos + 1);

//    cout << "\npos : " << pos << "\n";
//    cout << "prefix : " << prefix << "\n";
//    cout << "suffix : " << suffix << "\n";

    for (int i = 0; i < cnt; i++) {
        cin >> input;
//        cout << "inputPrefix : " << input.substr(0, pos) << "\n";
//        cout << "inputSuffix : " << input.substr(input.length() - suffix.size()) << "\n\n";
        if (prefix.size() + /**/suffix.size() > input.size()) cout << "NE\n";
        else {
            if (input.substr(0, pos) == prefix && input.substr(input.size() - suffix.length()) == suffix)cout << "DA\n";
            else cout << "NE\n";
        }
    }
}
