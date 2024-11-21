#include <bits/stdc++.h>

using namespace std;

void move(char c) {
    bool isSmall = 'a' <= c && c <= 'z';
    bool isBig = 'A' <= c && c <= 'Z';

    int index = c + 13;

    if ((isSmall && index <= 'z') || (isBig && index <= 'Z')) {
        cout << (char)index;
        return;
    }

    if (isSmall) {
        cout << (char)(index - ('z' - 'a' + 1));
        return;
    }

    if (isBig) {
        cout << (char)(index - ('Z' - 'A' + 1));
        return;
    }

    cout << c;
}

int main() {
    string input;
    getline(cin, input);
    for (char c : input) move(c);
}