//
// Created by SeongHeon Sim on 2023/04/03.
//
#include <bits/stdc++.h>

using namespace std;

// 암호화 > 알파벳 위치 +13
// 복호화 > 암호화된 알파벳 위치 +13
// 예외 > 알파벳이 아닌 문자는 패스
// A : 65
// Z : 90
// a : 97
// z : 122

string input;

void encrypt(char c, bool isBig) {
    int start = 'a';
    if (isBig) start = 'A';
    int result = c - start + 13;
    if (26 <= result) result -= 26;
    cout << (char) (result + start);
}

int main() {
    getline(cin, input);

    for (char c: input) {
        if ('A' <= c && c <= 'Z') {
            encrypt(c, true);
        } else if ('a' <= c && c <= 'z') {
            encrypt(c, false);
        } else {
            cout << c;
        }
    }
}
