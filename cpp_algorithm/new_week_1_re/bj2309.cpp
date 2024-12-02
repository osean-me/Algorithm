#include <bits/stdc++.h>

using namespace std;

// 1. 순열로 구현
void solve_1(vector<int> &v) {
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        for (auto it = v.begin(); it < v.begin() + 7; it++) {
            sum += *it;
        }
        if (sum == 100) break;
    } while (next_permutation(v.begin(), v.end()));

    for (auto it = v.begin(); it < v.begin() + 7; it++) cout << *it << "\n";
}

// 2. 조합으로 구현
void solve_2(vector<int> &v, int r, int depth) {
    if (r == depth) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += v[i];

        if (sum == 100) {
            sort(v.begin(), v.begin() + 7);
            for (int i = 0; i < r; i++) cout << v[i] << "\n";
            exit(0);
        }
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        swap(v[i], v[depth]);
        solve_2(v, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

// 3. 누적합으로 구현
void solve_3(vector<int> &v, int psum) {
    pair<int, int> ret;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (psum - v[i] - v[j] == 100) {
                ret = {i, j};
                break;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        if (i == ret.first || i == ret.second) continue;
        result.push_back(v[i]);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < 7; i++) cout << result[i] << "\n";
}

int main() {
    vector<int> arr;
    int psum = 0;
    for (int i = 0; i < 9; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        psum += input;
    }
    solve_1(arr);
    solve_2(arr, 7, 0);
    solve_3(arr, psum);
}