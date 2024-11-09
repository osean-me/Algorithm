#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> &key) {
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key[i].size(); j++) {
            cout << key[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate_left_90(vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = key[j][m - i - 1];
        }
    }

    key.resize(m);
    key[0].resize(n);
    key = temp;

    return;
}

void rotate_right_90(vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> temp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = key[n - j - 1][i];
        }
    }

    key.resize(m);
    key[0].resize(n);
    key = temp;

    return;
}

void symmetry(vector<vector<int>> &key) {
    int n = key.size();
    int m = key[0].size();

    if (n != m) {
        cout << "대칭 만들기 불가!\n";
        return;
    }
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = key[j][i];
        }
    }

    key = temp;

    return;
}

int main() {
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // 좌측으로 90' 이동
    rotate_left_90(v);
    print(v);
    // 다시 우측으로 90' 이동
    rotate_right_90(v);
    print(v);
    // 대칭 만들기
    symmetry(v);
    print(v);

    v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    symmetry(v);
    print(v);

    return 0;
}