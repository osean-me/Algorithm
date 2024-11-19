#include <bits/stdc++.h>

using namespace std;

int main() {
    // 난쟁이 9명
    vector<int> arr(9);

    // 난쟁이들의 키 입력
    for (auto it = arr.begin(); it < arr.end(); it++) {
        cin >> *it;
    }

    // 난쟁이 키 오름차순으로 정렬
    sort(arr.begin(), arr.end());

    // 순열로 처리하면서 0~6번 난쟁이의 키의 합이 100인 경우 반복문 종료
    do {
        int sum = 0;
        for (auto it = arr.begin(); it < arr.end() - 2; it++) {
            sum += *it;
        }

        if (sum == 100) break;
    } while (next_permutation(arr.begin(), arr.end()));

    for (auto it = arr.begin(); it < arr.end() - 2; it++) cout << *it << "\n";

    return 0;
}