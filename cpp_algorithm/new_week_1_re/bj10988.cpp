#include <bits/stdc++.h>

using namespace std;

// 펠린드롬은 전체를 반대로 뒤집어도 동일해야 한다.
int main() {
    string a;
    cin >> a;

    string b = a;
    reverse(b.begin(), b.end());

    if (a == b) {
        cout << 1;
    } else {
        cout << 0;
    }
}