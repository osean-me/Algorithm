#include <bits/stdc++.h>
using namespace std;
#define prev seumbal

int n, t, asum, bsum, ascore, bscore;
string tml, prev;

void print(int total) {
    string m = "00" + to_string(total / 60);
    string s = "00" + to_string(total % 60);
    cout << m.substr(m.size() - 2, 2) << ":" << s.substr(s.size() - 2, 2)
         << "\n";
}

int convert(string timeline) {
    return atoi(timeline.substr(0, 2).c_str()) * 60 +
           atoi(timeline.substr(3, 2).c_str());
}

void sum(int &sum, string timeline) {
    sum += (convert(timeline) - convert(prev));
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