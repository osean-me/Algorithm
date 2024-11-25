#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, result = 0;
    long long M;
    int arr[15001] = {};
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == M) result++;
        }
    }

    cout << result;
}