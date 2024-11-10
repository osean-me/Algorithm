#include <bits/stdc++.h>

using namespace std;

/*
승철이는 뇌를 잃어버렸다.
학교에 갔더니 선생님이 자연수로 이루어진 N개의 카드를 주며 M개의 질문을 던진다.
그 질문은 나열한 카드 중 A번째부터 B번째까지의 합을 구하는 것이다.
뇌를 잃어버렸기 때문에 승철이는 이 문제를 풀 수 없다.
문제를 풀 수 있는 프로그램을 작성해보자.

입력
수의 개수 N, 합을 구해야 하는 횟수 M, 그 이후 N개의 수가 주어진다.
수는 100이하의 자연수.
그 이후 M개의 줄에는 합을 구해야 하는 구간 A, B가 주어진다.

출력
M개의 줄에 A부터 B까지의 합을 구하라.

*/

// 시간 복잡도 : O(10만 * 10만) > 시간 초과 발생!
void solve_a() {
    int n, m;
    cin >> n >> m;
    int array[n];
    // n 개의 자연수
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // m 개의 누적합
    int result[m];
    for (int i = 0; i < m; i++) {
        int a, b, sum = 0;
        cin >> a >> b;

        for (int j = a - 1; j < b; j++) {
            sum += array[j];
        }
        result[i] = sum;
    }

    for (int value : result) cout << value << "\n";
}

// 누적합을 사용한다면?
// 시간 복잡도 : O(1)
void solve_b() {
    int n, m;
    cin >> n >> m;
    int array[n];
    int prefixSum[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        prefixSum[i] = prefixSum[i - 1] + array[i];
    }

    int result[m];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        result[i] = prefixSum[b] - prefixSum[a - 1];
    }

    for (int value : result) cout << value << "\n";
    return;
}

int main() {
    cout << "solve_a 처리 로직\n";
    solve_a();
    cout << "solve_b 처리 로직\n";
    solve_b();
    return 0;
}