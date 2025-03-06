#include <bits/stdc++.h>

using namespace std;

const string V = "2400";

int n, i;
long long t = 2400;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (true) {
        if (i == n) {
            cout << s;
            break;
        }
        s = to_string(t);
        size_t pos = s.find(V);
        if (pos != string::npos) {
            i++;
        }
        t++;
    }
}