#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<char> expr;

int ctoi(char c) { return c - '0'; }

int calculate(int x, char symbol, int y) {
    if (symbol == '-') return x - y;
    if (symbol == '*') return x * y;
    if (symbol == '/') return x / y;
    return x + y;
}

int solution(int i, int sum) {
    if (i >= n - 1) return sum;

    int a = solution(i + 2, calculate(sum, expr[i + 1], ctoi(expr[i + 2])));
    int b = INT_MIN;

    if (i + 4 <= n) {
        int temp = calculate(ctoi(expr[i + 2]), expr[i + 3], ctoi(expr[i + 4]));
        b = solution(i + 4, calculate(sum, expr[i + 1], temp));
    }

    return max(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for (char c : s) expr.push_back(c);
    cout << solution(0, ctoi(expr[0]));
}