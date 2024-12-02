#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    int arr['z' - 'a' + 1] = {};
    cin >> input;

    for (char c : input) arr[c - 'a']++;
    for (int cnt : arr) cout << cnt << " ";
}