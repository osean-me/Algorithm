#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> vec(5, vector<string>(15, ""));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < vec.size(); i++) {
        string input;
        getline(cin, input);

        for (int j = 0; j < input.size(); j++) {
            vec[i][j] = input[j];
        }
    }

    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < vec.size(); i++) cout << vec[i][j];
    }
}