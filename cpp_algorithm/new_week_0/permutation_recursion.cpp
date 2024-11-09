#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &n, int r) {
    for (int i = 0; i < r; i++) {
        cout << *&n[i] << " ";
    }
    cout << '\n';
}

void makePermutation(vector<int> &n, int r, int depth) {
    if (r == depth) {
        print(n, r);
        return;
    }
    for (int i = depth; i < n.size(); i++) {
        swap(n[i], n[depth]);
        makePermutation(n, r, depth + 1);
        swap(n[i], n[depth]);
    }
}

int main() {
    vector<int> v;
    int r;
    cin >> r;
    for (int i = 0; i < 3; i++) {
        v.push_back(i + 1);
    }
    makePermutation(v, r, 0);
    return 0;
}