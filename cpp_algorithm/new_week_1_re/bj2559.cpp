#include <bits/stdc++.h>

using namespace std;

// 맞왜틀??
// 누적합까지 아이디어를 떠올린 것은 좋았으나 조금 더 깊이있게 생각하지 못함
int main() {
    int n = 0, k = 0;
    cin >> n >> k;

    int arr[100001] = {};

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        arr[i] = arr[i - 1] + input;
    }

    // 더한 값이 음수인 경우도 있으니까 result 는 -10,000,000 보다 작게 시작
    int result = -10000001;
    // i 는 k 부터 시작해야 한다.
    // k 보다 밑에 있는 누적합 값을 참조할 수 있기 때문이다.
    for (int i = k; k <= n; k++) {
        result = max(result, arr[i] - arr[i - k]);
    }

    cout << result;
}