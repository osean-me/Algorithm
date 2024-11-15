#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    int arr[1000] = {};
    for (char c : S) arr[(int)c]++;
    for (char c = 'a'; c <= 'z'; c++) cout << arr[(int)c] << ' ';

    return 0;
}