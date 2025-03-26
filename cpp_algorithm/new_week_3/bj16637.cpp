#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MIN;
string s;
vector<int> nums;
vector<char> symbols;

int calculate(int a, int b, char symbol) {
    if (symbol == '+') return a + b;
    if (symbol == '-') return a - b;
    return a * b;
}

void go(int idx, int value) {
    if (idx == nums.size() - 1) {
        ret = max(ret, value);
        return;
    }

    int n_value = calculate(value, nums[idx + 1], symbols[idx]);
    go(idx + 1, n_value);

    if (idx + 2 < nums.size()) {
        int bracket = calculate(nums[idx + 1], nums[idx + 2], symbols[idx + 1]);
        int n_value = calculate(value, bracket, symbols[idx]);
        go(idx + 2, n_value);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;

    for (char c : s) {
        if ('0' <= c && c <= '9') {
            nums.push_back(c - '0');
        } else {
            symbols.push_back(c);
        }
    }

    go(0, nums[0]);
    cout << ret;
}