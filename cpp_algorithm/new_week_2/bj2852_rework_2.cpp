#include <bits/stdc++.h>
#define prev default_value
using namespace std;

int n, t, ascore = 0, bscore = 0, asum = 0, bsum = 0;
string tml, prev;

int convertSecond(string timeline) {
    int m = stoi(timeline.substr(0, 2));
    int s = stoi(timeline.substr(3));
    return (m * 60) + s;
}

void sum(int &tsum, string timeline) {
    tsum += (convertSecond(timeline) - convertSecond(prev));
}

void print(int tsum) {
    string m = "00" + to_string(tsum / 60);
    string s = "00" + to_string(tsum % 60);
    cout << m.substr(m.size() - 2, 2) << ":" << s.substr(s.size() - 2, 2)
         << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t >> tml;
        if (ascore > bscore) {
            sum(asum, tml);
        } else if (ascore < bscore) {
            sum(bsum, tml);
        }
        t == 1 ? ascore++ : bscore++;
        prev = tml;
    }

    if (ascore > bscore) {
        sum(asum, "48:00");
    } else if (ascore < bscore) {
        sum(bsum, "48:00");
    }

    print(asum);
    print(bsum);
}