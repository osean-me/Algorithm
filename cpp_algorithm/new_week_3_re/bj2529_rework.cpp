#include <bits/stdc++.h>

using namespace std;

int n;
char signs[10];
bool visited[10];
vector<string> nums;

bool compare(int a, char sign, int b) {
    if (sign == '<') return a < b;
    if (sign == '>') return a > b;
    return false;
}

void solution(int idx, string num) {
    if (idx == (n + 1)) {
        nums.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;
        if (idx == 0 || compare(num[idx - 1] - '0', signs[idx - 1], i)) {
            visited[i] = true;
            solution(idx + 1, num + to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> signs[i];

    solution(0, "");
    cout << nums.back() << "\n" << *nums.begin();
}