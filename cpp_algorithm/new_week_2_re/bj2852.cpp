#include <bits/stdc++.h>

using namespace std;

int n, t, m, s, ni, ct, nt;
string goalTime;
vector<pair<int, int>> roundResults;
vector<int> scores(3, 0), leadingTime(3, 0);

void print(int totalLeadingTime) {
    int tm = totalLeadingTime / 60;
    int ts = totalLeadingTime % 60;
    string am = to_string(tm);
    string as = to_string(ts);

    if (tm == 0) am = "00";
    if (ts == 0) as = "00";
    if (tm != 0 && tm / 10 == 0) am = "0" + am;
    if (ts != 0 && ts / 10 == 0) as = "0" + as;

    cout << am << ":" << as << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> goalTime;
        m = stoi(goalTime.substr(0, 2)) * 60;  // 득점 분 > 초로 변경
        s = stoi(goalTime.substr(3));          // 득점 초
        roundResults.push_back({t, m + s});    // 현재 라운드의 팀 별 득점 시간
    }

    for (int i = 0; i < roundResults.size(); i++) {
        scores[roundResults[i].first]++;  // 현재 라운드에서 i팀 득점 기록
        ni = i + 1;                       // 다음 라운드

        ct = roundResults[i].second;  // 현재 라운드의 득점 시간
        nt = 2880;  // 다음 라운드의 득점 시간(기본값 : 게임 종료 시간)
        // 마지막 라운드가 아니면 다음 라운드의 득점 시간
        if (ni < roundResults.size()) nt = roundResults[ni].second;

        if (scores[1] > scores[2]) {
            // 1팀이 이기는 경우
            leadingTime[1] += (nt - ct);
        } else if (scores[1] < scores[2]) {
            // 2팀이 이기는 경우
            leadingTime[2] += (nt - ct);
        }
    }

    print(leadingTime[1]);
    print(leadingTime[2]);
}