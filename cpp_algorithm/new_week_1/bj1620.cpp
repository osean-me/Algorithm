#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string nameToNum[N];
    unordered_map<string, int> numToName;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        nameToNum[i] = name;
        numToName[name] = i;
    }

    string questions[M];
    for (int i = 0; i < M; i++) {
        string q;
        cin >> q;
        questions[i] = q;
    }

    for (int i = 0; i < M; i++) {
        try {
            int num = stoi(questions[i]);
            cout << nameToNum[num - 1] << "\n";
        } catch (const std::exception& e) {
            cout << numToName[questions[i]] + 1 << "\n";
        }
    }
}