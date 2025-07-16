#include <bits/stdc++.h>

using namespace std;

int main() {
    int S, idx;
    cin >> S >> idx;
    S ^= (1 << idx);
    cout << S;
}