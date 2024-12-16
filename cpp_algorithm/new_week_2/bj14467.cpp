#include <bits/stdc++.h>

using namespace std;

// n = 관찰 횟수
int n, result = 0;
// 소 번호 : 소 움직인 좌표
vector<stack<int>> cows(11, stack<int>());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, place;
        cin >> num >> place;

        // 소 움직인 좌표가 비어 있으면 push
        if (cows[num].empty()) {
            cows[num].push(place);
        } else {
            //  직전의 소 위치와 현재 소 위치가 다르면 push
            if (cows[num].top() != place) {
                cows[num].push(place);
            }
        }
    }

    for (stack<int> moves : cows) {
        // 소의 첫 번째 위치는 이동한 것이 아니므로 -1
        if (!moves.empty()) result += (moves.size() - 1);
    }
    cout << result;
}