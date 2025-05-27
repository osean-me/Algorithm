#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<char> expr;

int toi(char c) { return c - '0'; }

int calculate(int prev, char symbol, int next) {
    if (symbol == '-') return prev - next;
    if (symbol == '*') return prev * next;
    if (symbol == '/') return prev / next;
    return prev + next;
}

int go(int idx, int value) {
    if (idx >= n - 1) return value;
    int a = go(idx + 2, calculate(value, expr[idx + 1], toi(expr[idx + 2])));

    int b = INT_MIN;
    if (idx + 4 <= n) {
        int temp =
            calculate(toi(expr[idx + 2]), expr[idx + 3], toi(expr[idx + 4]));
        b = go(idx + 4, calculate(value, expr[idx + 1], temp));
    }
    return max(a, b);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) expr.push_back(s[i]);
    cout << go(0, toi(expr[0]));
}