#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MIN;
string s;
vector<int> nums;
vector<int> symbols;

int calculate(int x, int y, int symbol) {
    if (symbol == '+') return x + y;
    if (symbol == '-') return x - y;
    return x * y;
}

void go(int idx, int sum) {
    if (idx == nums.size() - 1) {
        ret = max(ret, sum);
        return;
    }

    int psum = calculate(sum, nums[idx + 1], symbols[idx]);
    go(idx + 1, psum);

    if (idx + 2 < nums.size()) {
        int bracket = calculate(nums[idx + 1], nums[idx + 2], symbols[idx + 1]);
        int nsum = calculate(sum, bracket, symbols[idx]);
        go(idx + 2, nsum);
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