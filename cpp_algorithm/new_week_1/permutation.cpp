#include <bits/stdc++.h>

using namespace std;

void printV(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    int a[3] = {1, 2, 3};
    vector<int> v;

    // 오름차순 순열 출력
    for (int i = 0; i < 3; i++) {
        v.push_back(a[i]);
    }

    do {
        printV(v);
    } while (next_permutation(v.begin(), v.end()));

    v.clear();
    cout << "\n";

    // 내림차순 순열 출력
    for (int i = 2; i >= 0; i--) {
        v.push_back(a[i]);
    }

    do {
        printV(v);
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}