#include <bits/stdc++.h>

using namespace std;

int n;
string s;
stack<char> stck;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s) {
            if (stck.empty()) {
                stck.push(c);
                continue;
            }

            if (stck.top() == '(' && c == ')') {
                stck.pop();
                continue;
            }

            stck.push(c);
        }

        cout << (stck.empty() ? "YES\n" : "NO\n");
        stck = stack<char>();
    }
}