#include <bits/stdc++.h>

using namespace std;

char t;
string s;
stack<char> stck;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (getline(cin, s)) {
        stck = stack<char>();
        if (s == ".") break;

        for (char c : s) {
            if (!(c == '(' || c == ')' || c == '[' || c == ']')) continue;
            if (stck.empty()) {
                stck.push(c);
                continue;
            }

            t = stck.top();

            if ((t == '(' && c == ')') || (t == '[' && c == ']')) {
                stck.pop();
                continue;
            }

            stck.push(c);
        }

        cout << (stck.empty() ? "yes\n" : "no\n");
    }
}