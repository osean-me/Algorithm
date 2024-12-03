#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string pattern;
    cin >> n >> pattern;

    int center = pattern.find('*');
    string prefix = pattern.substr(0, center);
    string suffix = pattern.substr(center + 1);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (name.size() < prefix.size() + suffix.size()) {
            cout << "NE\n";
            continue;
        }

        string nPrefix = name.substr(0, prefix.size());
        string nSuffix = name.substr(name.size() - suffix.size());

        if (nPrefix == prefix && nSuffix == suffix) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
}