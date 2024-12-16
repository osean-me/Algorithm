#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c;
vector<int> vec(4000, 0);

void func_1() { vec[b] = c; }

void func_2() {
    for (int i = b; i < c; i++) {
        if (vec[i]) {
            vec[i] = 0;
        } else {
            vec[i] = 1;
        }
    }
}

void func_3() {
    for (int i = b; i < c; i++) vec[i] = 0;
}

void func_4() {
    for (int i = b; i < c; i++) vec[i] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> vec[i];

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        b--;
        if (a == 1)
            func_1();
        else if (a == 2)
            func_2();
        else if (a == 3)
            func_3();
        else if (a == 4)
            func_4();
    }

    for (int i = 0; i < n; i++) cout << vec[i] << " ";
}