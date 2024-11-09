#include <bits/stdc++.h>

using namespace std;

void call_next_permutation(vector<int> &v) {
    do {
        for (int i = 0; i < v.size(); i++) {
            cout << *&v[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
}

void recursion(vector<int> &v, int r, int depth) {
    if (r == depth) {
        for (int i = 0; i < r; i++) {
            cout << *&v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = depth; i < v.size(); i++) {
        swap(v[i], v[depth]);
        recursion(v, r, depth + 1);
        swap(v[depth], v[i]);
    }
}

int main() {
    int n;
    cin >> n;
    int r;
    cin >> r;

    // 벡터 객체 생성
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i + 1);
    }

    recursion(v, r, 0);
    cout << "\n";
    call_next_permutation(v);
    return 0;
}