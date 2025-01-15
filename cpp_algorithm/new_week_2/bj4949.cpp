#include <bits/stdc++.h>

using namespace std;

string s;
stack<char> chars;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (getline(cin, s)) {
        if (s == ".") break;

        for (char c : s) {
            if (c != '(' && c != ')' && c != '[' && c != ']') continue;

            if (chars.empty()) {
                chars.push(c);
                continue;
            }

            if ((chars.top() == '(' && c == ')') ||
                (chars.top() == '[' && c == ']')) {
                chars.pop();
            } else {
                chars.push(c);
            }
        }
        cout << (chars.size() == 0 ? "yes" : "no") << "\n";
        chars = stack<char>();
    }
}