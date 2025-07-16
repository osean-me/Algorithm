#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, idx;
    cin >> num >> idx;
    num |= (1 << idx);
    cout << num;
}