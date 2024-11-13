#include <bits/stdc++.h>

using namespace std;

int main() {
    // 배열의 크기
    int n;
    cin >> n;

    // 숫자 배열 입력 및 누적합
    vector<int> arr(n);
    vector<double> psum = {0};
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        psum.push_back(psum.back() + input);
    }

    sort(arr.begin(), arr.end());
    for (int i : arr) cout << i << " ";
    double average = psum.back() / n;
    cout << "\n" << fixed << setprecision(2) << average;

    return 0;
}