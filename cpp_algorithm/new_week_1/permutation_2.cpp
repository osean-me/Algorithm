#include <bits/stdc++.h>

using namespace std;

void permutationWithArray() {
    cout << "정렬되어 있지 않은 배열" << "\n";
    int a[] = {1, 3, 2};
    do {
        for (int i : a) {
            cout << i << " ";
        }
        cout << "\n";
    } while (next_permutation(a, a + 3));

    cout << "정렬되어 있는 배열" << "\n";
    sort(a, a + 3);
    do {
        for (int i : a) {
            cout << i << " ";
        }
        cout << "\n";
    } while (next_permutation(&a[0], &a[3]));
}

void permutationWithVector() {
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }
    int i = 0;
    do {
        cout << i << " : ";
        for (auto a : v) {
            cout << a << " ";
        }
        cout << '\n';
        i++;
    } while (next_permutation(v.begin(), v.end()));
}

void permutation_principle() {
    int a[] = {1, 6, 3, 5, 8};
    sort(a, a + 5);
    int flag = 1;
    do {
        flag = next_permutation(a, a + 5);
        cout << "flag " << flag << "\n";
        for (int i : a) cout << i << " ";
        cout << '\n';
    } while (flag);
}

/**
 * 순열 함수(next_permutation, prev_permutation)를 사용하려면
 * 사전에 대상 데이터가 정렬이 되어 있어야 한다.
 * 정렬이 되어 있지 않은 경우, 현재 정렬된 기준으로부터 조합을 계산하기 때문에
 * (next_permutation 의 경우, 다음 번째 순열을 만들어내는 함수)
 * 의도한 바와 다른 값이 나올 수 있다.
 */
int main() {
    permutationWithArray();
    permutationWithVector();
    permutation_principle();
    return 0;
}