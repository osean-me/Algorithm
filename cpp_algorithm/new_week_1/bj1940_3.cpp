#include <bits/stdc++.h>

using namespace std;

int N, M, arr[15001], cnt;

void combi(int index, vector<int> &v) {
    if (v.size() == 2) {
        int a = arr[v[0]];
        int b = arr[v[1]];
        if (a + b == M) cnt++;
        return;
    }

    for (int i = index + 1; i < N; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<int> v;
    combi(-1, v);
    cout << cnt;
}