#include <bits/stdc++.h>

using namespace std;

int k, used[10];
char c_arr[9];
vector<string> results;

bool isValid(char op, int a, int b) {
    if (op == '<') return a < b;
    if (op == '>') return a > b;
    return false;
}

void go(int idx, string num) {
    if (idx == k + 1) {
        results.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        if (idx == 0 || isValid(c_arr[idx - 1], num[idx - 1] - '0', i)) {
            used[i] = true;
            go(idx + 1, num + to_string(i));
            used[i] = false;
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> c_arr[i];
    go(0, "");
    cout << results.back() << "\n" << *results.begin();
}