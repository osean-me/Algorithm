#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "It's hard to have a score leg";

    reverse(a.begin(), a.end());
    cout << a << "\n";  // gel eros a evah ot drah s'tI

    reverse(a.begin(), a.end());
    cout << a << "\n";  // It's hard to have a score leg

    reverse(a.begin() + 3, a.end());
    cout << a << "\n";  // It'gel erocs a evah ot drah s
    return 0;
}