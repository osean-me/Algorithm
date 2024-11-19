#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    int arr['z' - 'a' + 1] = {};
    for (int c : S) arr[c - 'a']++;
    for (int i = 'a'; i <= 'z'; i++) cout << arr[i - 'a'] << " ";

    return 0;
}