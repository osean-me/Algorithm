#include <bits/stdc++.h>

using namespace std;

int n, cnt, i = 666;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    while (cnt < n) {
        s = to_string(i);
        size_t pos = s.find("666");
        if (pos != string::npos) {
            cnt++;
        }

        if (cnt == n) {
            cout << s;
        }

        i++;
    }
}