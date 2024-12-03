#include <bits/stdc++.h>

using namespace std;

// 문제 입력 반복문 처리 후 출력 반복문 처리 시간초과 발생 X
// 문제 입력 + 출력 반복문 처리 시 시간초과 발생 O
// 예상하기에 후자의 경우 반복문을 돌 때 마다 입력과 이를 숫자형으로 컨버팅하는
// 과정에서 시간이 오래걸려 총 시간이 많이 소요되는 것 같다.
int main() {
    // 입출력 최적화를 적용하니 시간초과 발생 X
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string names[100001];
    unordered_map<string, int> nameMap;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        names[i] = name;
        nameMap[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string question;
        cin >> question;
        int num = atoi(question.c_str());
        if (num) {
            cout << names[num] << "\n";
        } else {
            cout << nameMap[question] << "\n";
        }
    }
}