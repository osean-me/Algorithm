#include <bits/stdc++.h>

using namespace std;

int main() {
    int count, targetIndex;
    string pattern, prefix, suffix;
    cin >> count >> pattern;
    cin.ignore();

    targetIndex = pattern.find("*");
    prefix = pattern.substr(0, targetIndex);
    suffix = pattern.substr(targetIndex + 1);

    for (int i = 0; i < count; i++) {
        string input;
        getline(cin, input);

        if ((prefix.length() + suffix.length()) > input.length()) {
            cout << "NE\n";
            continue;
        }

        string thisPrefix = input.substr(0, targetIndex);
        string thisSuffix = input.substr(input.length() - suffix.length());

        if (prefix == thisPrefix && suffix == thisSuffix) {
            cout << "DA\n";
            continue;
        } else {
            cout << "NE\n";
            continue;
        }
    }
}