//
// Created by SeongHeon Sim on 2023/04/16.
//
#include <bits/stdc++.h>

using namespace std;

string input = "";
int alphabet[95] = {};

bool checkEven() {
    bool isEven = input.length() % 2 == 0;
    for (char c = 'A'; c <= 'Z'; c++) if (isEven && alphabet[c] % 2 != 0) return false;
    return true;
}

bool checkOdd() {
    bool isOdd = input.length() % 2 != 0;
    if (!isOdd) return true;
    int oddCnt = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (alphabet[c] % 2 != 0) oddCnt++;
        if (oddCnt > 1) return false;
    }
    return true;
}

string palindrome() {
    char center = ' ';
    string prefix = "";
    string suffix = "";
    for (char c = 'A'; c <= 'Z'; c++) {
        int size = alphabet[c];
        if (size % 2 != 0) center = c;
        for (int i = 0; i < size / 2; i++) {
            prefix += c;
            suffix = (c + suffix);
        }
    }
    if (center != ' ') return prefix + center + suffix;
    return prefix + suffix;
}

int main() {
    cin >> input;
    for (int i = 0; i < input.length(); i++) alphabet[input[i]]++;
    if (!checkEven() || !checkOdd()) cout << "I'm Sorry Hansoo";
    else cout << palindrome();
};
