#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int length = 1;
        long long k = 1;
        while (k % n != 0) {
            if (k % n == 0) {
                break;
            } else {
                length++;
                k = ((k * 10) + 1) % n;
            }
        }
        cout << length << "\n";
    }
}