#include <bits/stdc++.h>

using namespace std;

int n, result = 0;
string input;
vector<int> v(10, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> input;

    for (char c : input) v[c - '0']++;

    for (int i = 0; i < v.size(); i++) result += (i * v[i]);
    cout << result;
}