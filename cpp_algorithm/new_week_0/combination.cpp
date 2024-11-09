#include <bits/stdc++.h>

using namespace std;

void makeCombination(vector<int> &v, int limit, int depth) {
    if (limit == depth) {
        for (int i = 0; i < limit; i++) {
            cout << *&v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = depth; i < limit; i++) {
        swap(v[i], v[i + 1]);
        makeCombination(v, limit, depth + 1);
        swap(v[i], v[i + 1]);
    }
}

int main() {
    vector<int> v;
    int n;
    int r;
    cin >> n;
    cin >> r;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }
    makeCombination(v, r, 0);
    return 0;
}