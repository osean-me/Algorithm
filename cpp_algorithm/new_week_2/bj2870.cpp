#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> adj;
vector<int> nums(101, -1);

bool validateNumber(char c) { return '0' <= c && c <= '9'; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (validateNumber(s[i])) nums[i] = (s[i] - '0');
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) continue;

            string nstr;
            int start = i;
            int end = i + 1;

            for (int j = start + 1; j < nums.size(); j++) {
                if (nums[j] == -1) {
                    end = j;
                    break;
                }
            }

            for (int j = start; j < end; j++) {
                if (j == start && nums[j] == 0) continue;
                nstr += to_string(nums[j]);
            }

            adj.push_back(nstr);
            i = end;
        }

        nums = vector<int>(101, -1);
    }

    sort(adj.begin(), adj.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;  // 길이가 같으면 사전순 비교
        return a.size() < b.size();              // 길이가 다르면 짧은 것이 작음
    });

    for (string i : adj) cout << i << "\n";
}