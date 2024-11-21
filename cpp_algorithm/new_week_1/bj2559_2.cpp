#include <bits/stdc++.h>

using namespace std;

// 누적합(구간합)을 이용해서 문제를 푼다.
// 구간합의 경우 찾고자 하는 마지막, 시작점 인덱스의 누적합 값을 빼주면 된다.
int main() {
    int N, K, maximum = -10000004;
    cin >> N >> K;
    int psum[N + 1];

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        psum[i] = psum[i - 1] + input;
    }

    for (int i = K; i <= N; i++) {
        maximum = max(maximum, psum[i] - psum[i - K]);
    }

    cout << maximum;
}