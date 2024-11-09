#include <bits/stdc++.h>

using namespace std;

int a[3] = {1, 2, 3};

int main() {
    int *c = a;
    cout << c << "\n";
    cout << &a[0] << "\n";
    cout << c + 1 << "\n";
    cout << &a[1] << "\n";
    cout << c + 2 << "\n";
    cout << &a[2] << "\n";
    return 0;
}