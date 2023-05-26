//
// Created by SeongHeon Sim on 2023/04/14.
//
#include <bits/stdc++.h>

using namespace std;

int t, n;
string a, b;

int main() {
    cin >> t;
    while (t--) {
        map<string, int> _map = map<string, int>();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            _map[b]++;
        }
        long long let = 1;
        for (auto p: _map) {
            let *= ((long long) p.second) + 1;
        }
        let--;
        cout << let << "\n";
    }
}
/*
1
6
hat headgear
sunglasses eyewear
turban headgear
mask face
lip face
makeup face

1
3
hat headgear
sunglasses eyewear
turban headgear
 */
