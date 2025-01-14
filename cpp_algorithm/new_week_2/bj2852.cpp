#include <bits/stdc++.h>

using namespace std;

int n, t, as, bs;
string tm;
// 타임라인 > 팀 별 점수(key), 분과 초(value)
vector<vector<vector<int>>> timeline(101,
                                     vector<vector<int>>(2, vector<int>(3, 0)));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> tm;
        int m = stoi(tm.substr(0, 2));
        int s = stoi(tm.substr(3));

        // 점수가 입력되면 현재 스코어를 비교
        int t1 = t - 1;
        if (t1 == 0) as++;
        if (t1 == 1) bs++;
        int t2 = !t1;
        if (timeline[i].empty()) {
            timeline[i][t1][0] = 1;
            timeline[i][t1][1] = (m * 60) + s;
        } else {
            if (t1 == 0) {
                timeline[i][t1][0] = as;
                timeline[i][t2][0] = bs;
                timeline[i][t1][1] = (m * 60) + s;
            } else {
                timeline[i][t2][0] = as;
                timeline[i][t1][0] = bs;
                timeline[i][t1][1] = (m * 60) + s;
            }
        }
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << "게임 " << (i + 1) << "\n";
        for (int j = 0; j < timeline[i].size(); j++) {
            cout << "   팀" << (j + 1) << "\n";
            cout << "       점수: " << timeline[i][j][0]
                 << ", 시간: " << timeline[i][j][1] / 60 << "분 "
                 << timeline[i][j][1] % 60 << "초\n";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < timeline[i].size(); j++) {
            int aScore = timeline[i][j][0], bScore = timeline[i][j][1];
            if (aScore > bScore) {
            }
        }
    }
}