#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    for (char c : input) {
        auto movedC = (c + 13);
        if ('A' <= c && c <= 'Z') {
            if (movedC > 'Z') {
                movedC -= 'Z';
                movedC += ('A' - 1);
            }
            c = movedC;
        } else if ('a' <= c && c <= 'z') {
            if (movedC > 'z') {
                movedC -= 'z';
                movedC += ('a' - 1);
            }
            c = movedC;
        }

        cout << (char)c;
    }
}