#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string rs = s;
    reverse(rs.begin(), rs.end());
    if (s == rs)
        cout << true;
    else
        cout << false;
    return 0;
}