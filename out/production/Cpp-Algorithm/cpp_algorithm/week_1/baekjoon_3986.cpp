//
// Created by SeongHeon Sim on 2023/04/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input = "";
        cin >> input;
        vector<char> v = vector<char>();
        v.push_back(input[0]);
        for (int k = 1; k < input.length(); k++) {
            if (v[v.size() - 1] == input[k]) v.pop_back();
            else v.push_back(input[k]);
        }
        if (v.size() == 0) cnt++;
    }
    cout << cnt;
}
