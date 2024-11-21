#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr;
    vector<int> result;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for (auto it = arr.begin(); it < arr.end(); it++) {
        if (it + K > arr.end()) continue;
        int sum = accumulate(it, it + K, 0);
        result.push_back(sum);
    }

    cout << *max_element(result.begin(), result.end());
}