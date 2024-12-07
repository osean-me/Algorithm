#include <bits/stdc++.h>

using namespace std;

int main() {
    string name;
    cin >> name;
    sort(name.begin(), name.end());
    stack<char> container;
    string result;

    for (char c : name) {
        if (container.empty()) {
            container.push(c);
            continue;
        }

        if (container.top() == c) {
            container.pop();
            result += c;
            continue;
        }

        container.push(c);
    }

    if (container.size() < 2) {
        cout << result;
        if (container.size() == 1) {
            cout << container.top();
        }
        reverse(result.begin(), result.end());
        cout << result;
    } else {
        cout << "I'm Sorry Hansoo";
    }
}