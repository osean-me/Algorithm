#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int m = 1;
        long long k = 1;
        while (k % n != 0) {
            m++;
            k = ((k * 10) + 1) % n;
        }
        cout << m << "\n";
    }
}