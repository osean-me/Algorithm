#include <bits/stdc++.h>

using namespace std;

/**
 * 1.	초기화: combination 벡터를 (1, 2, ..., r) 형태로 초기화합니다.
 * 2.	출력 루프:
 *  •	현재 combination을 출력합니다.
 *  •	combination 벡터의 마지막 원소부터 역순으로 탐색하여, 가능한 가장 마지막
 * 요소를 증가시킵니다. 3.	다음 조합 생성: •	증가시킨 요소의 오른쪽에
 * 있는 값들은 하나씩 순차적으로 증가하도록 설정하여 새로운 조합을 만듭니다. 4.
 * 종료 조건: •	가장 왼쪽에 있는 요소(combination[0])가 증가할 수 없는 상태가
 * 되면 루프를 종료합니다.
 */
void combi_iterative(int n, int r) {
    vector<int> combination(r);  // r개의 원소를 선택할 벡터

    // 첫 번째 조합 초기화 (1, 2, ..., r)
    for (int i = 0; i < r; i++) {
        combination[i] = i + 1;
    }

    while (true) {
        // 현재 조합을 출력
        for (int i = 0; i < r; i++) {
            cout << combination[i] << " ";
        }
        cout << "\n";

        // 다음 조합을 찾기 위해 마지막 원소부터 증가 시도
        int i = r - 1;
        while (i >= 0 && combination[i] == n - r + i + 1) {
            i--;  // 뒤에서부터 가능한 위치 찾기
        }

        if (i < 0) break;  // 더 이상 조합이 없는 경우 종료

        // 조합 업데이트
        combination[i]++;
        for (int j = i + 1; j < r; j++) {
            combination[j] = combination[j - 1] + 1;
        }
    }
}

void combi_recursive(vector<int> &v, int n, int r, int start) {
    if (v.size() == r) {
        for (int i = 0; i < v.size(); i++) {
            cout << *&v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start + 1; i < n; i++) {
        v.push_back(i + 1);
        combi_recursive(v, n, r, i);
        v.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    int r;
    cin >> r;
    vector<int> v;
    // combi_recursive(v, n, r, -1);
    cout << "\n";
    combi_iterative(n, r);
    return 0;
}