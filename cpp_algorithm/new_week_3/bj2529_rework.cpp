#include <bits/stdc++.h>

using namespace std;

int k;
bool used[10];
char symbols[9];
vector<string> nums;

bool validation(char symbol, int a, int b) {
    if (symbol == '<') return a < b;
    if (symbol == '>') return a > b;
    return false;
}

void go(int idx, string num) {
    if (idx == k + 1) {
        nums.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (used[i]) continue;
        if (idx == 0 || validation(symbols[idx - 1], num[idx - 1] - '0', i)) {
            used[i] = true;
            go(idx + 1, num + to_string(i));
            used[i] = false;
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> symbols[i];

    go(0, "");
    cout << nums.back() << "\n" << *nums.begin();
}