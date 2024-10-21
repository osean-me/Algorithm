#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a = "aaabbb";
    // substr(위치, 크기)
    // 만약 인자가 하나만 들어가는 경우 해당 첫 번째부터 인자까지 제거한다.
    string b = a.substr(2);  // abbb
    cout << b << "\n";
    return 0;
}