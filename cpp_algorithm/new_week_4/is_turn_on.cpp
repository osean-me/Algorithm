#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, idx;
    cin >> num >> idx;

    if (num & (1 << idx)) {
        cout << idx << "번째는 켜져있다.";
    } else {
        cout << idx << "번째는 꺼져있다.";
    }
}