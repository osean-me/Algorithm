#include <bits/stdc++.h>

using namespace std;

int n, t, m, s, ni, clt, nlt;
string goalTime;
vector<pair<int, int>> leadingTime;
vector<int> score(3, 0), answer(3, 0);

void print(int team, int totalLeadingTime) {
    cout << team << " ";

    int tm = totalLeadingTime / 60;
    int ts = totalLeadingTime % 60;
    string sm = to_string(tm);
    string ss = to_string(ts);

    if (tm == 0) sm = "00";
    if (ts == 0) ss = "00";
    if (tm != 0 && tm / 10 == 0) sm = "0" + sm;
    if (ts != 0 && ts / 10 == 0) ss = "0" + ss;

    cout << sm << ":" << ss << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> goalTime;
        m = stoi(goalTime.substr(0, 2)) * 60;
        s = stoi(goalTime.substr(3));
        leadingTime.push_back({t, m + s});
    }

    for (int i = 0; i < n; i++) {
        score[leadingTime[i].first]++;
        ni = i + 1;
        clt = leadingTime[i].second;
        nlt = 2880;
        if (ni < n) nlt = leadingTime[ni].second;

        if (score[1] > score[2]) {
            answer[1] += (nlt - clt);
        } else if (score[1] < score[2]) {
            answer[2] += (nlt - clt);
        }
    }

    print(1, answer[1]);
    print(2, answer[2]);
}