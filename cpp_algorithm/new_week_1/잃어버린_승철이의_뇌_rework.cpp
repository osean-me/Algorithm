#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[N + 1];
    int psum[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }

    for (int s : psum) cout << s << " ";

    int result[M];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        result[i] = psum[b] - psum[a - 1];
    }

    for (int value : result) cout << value << "\n";
    return 0;
}