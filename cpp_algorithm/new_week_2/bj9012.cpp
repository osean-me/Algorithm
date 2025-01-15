#include <bits/stdc++.h>

using namespace std;

int n;
stack<char> chars;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            if (chars.empty()) {
                chars.push(s[j]);
                continue;
            }

            if (chars.top() == '(' && s[j] == ')') {
                chars.pop();
            } else {
                chars.push(s[j]);
            }
        }

        cout << (chars.size() == 0 ? "YES" : "NO") << "\n";
        chars = stack<char>();
    }
}