#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        stack<char> s;

        for (auto it = input.begin(); it < input.end(); it++) {
            if (s.empty()) {
                s.push(*it);
                continue;
            }

            if (s.top() == *it) {
                s.pop();
                continue;
            }

            s.push(*it);
        }

        if (s.empty()) cnt++;
    }

    cout << cnt;
}