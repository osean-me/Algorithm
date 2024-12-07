#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        stack<char> container;

        for (char c : s) {
            if (container.size() == 0) {
                container.push(c);
                continue;
            }

            if (container.top() == c) {
                container.pop();
                continue;
            }

            container.push(c);
        }

        if (container.size() == 0) cnt++;
    }

    cout << cnt;
}