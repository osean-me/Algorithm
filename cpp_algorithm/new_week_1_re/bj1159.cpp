#include <bits/stdc++.h>

using namespace std;

int main() {
    int total = 0;
    int lastNames['z' - 'a' + 1] = {};
    cin >> total;
    for (int i = 0; i < total; i++) {
        string name;
        cin >> name;
        lastNames[name[0] - 'a']++;
    }

    vector<char> result;
    for (int i = 'a'; i <= 'z'; i++) {
        if (lastNames[i - 'a'] >= 5) result.push_back(i);
    }

    if (result.empty()) {
        cout << "PREDAJA";
    } else {
        for (char c : result) cout << c;
    }
}