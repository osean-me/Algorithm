#include <bits/stdc++.h>

using namespace std;

int n, i, cnt;
size_t pos;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (cnt < n) {
        s = to_string(i);
        pos = s.find("666");
        if (pos != string::npos) cnt++;
        if (cnt == n) cout << i;
        i++;
    }
}