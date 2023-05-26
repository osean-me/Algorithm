//
// Created by SeongHeon Sim on 2023/03/30.
//
#include <bits/stdc++.h>

using namespace std;

int total;
map<char, int> nameCnt;
vector<char> v;

int main() {
    cin >> total;
    for (int i = 0; i < total; i++) {
        string input;
        cin >> input;
        nameCnt[input[0]]++;
    }

    for (pair<char, int> p: nameCnt) if (p.second > 4) v.push_back(p.first);
    sort(v.begin(), v.end());
    if (v.size() == 0) {
        cout << "PREDAJA";
        return 0;
    }
    for (char c: v) cout << c;
}
