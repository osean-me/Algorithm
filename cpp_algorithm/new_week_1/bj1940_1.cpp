#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, result = 0;
    long long M;
    /*
        배열의 길이가 최소 1000만이어야 하는 이유?
        갑옷 재료의 최대값이 100,000이라서 배열의 길이도
        100,001 정도로 설정할 경우 OutOfBound 에러 발생

        최악의 경우 M이 10,000,000일 때,
        갑옷 재료 a 를 M 에서 뺀 값이 100,000 보다 클 수 있기 때문이다.
     */
    int arr[10000001] = {};
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        arr[input]++;
    }

    for (long long i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
        long long j = M - i;
        if (j < 0) continue;
        if (i == j) continue;
        if (arr[i] == 0 || arr[j] == 0) continue;
        arr[i] = 0;
        arr[j] = 0;
        result++;
    }
    cout << result;
}