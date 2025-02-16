#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, c;
vector<ll> nums(1001, 0);
map<ll, vector<ll>> numToIndex;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        numToIndex[nums[i]].push_back(i);
    }

    vector<pair<ll, vector<ll>>> vec(numToIndex.begin(), numToIndex.end());
    sort(vec.begin(), vec.end(),
         [](const pair<ll, vector<ll>> &a, const pair<ll, vector<ll>> &b) {
             if (a.second.size() == b.second.size())
                 return a.second[0] < b.second[0];
             return a.second.size() > b.second.size();
         });

    for (pair<ll, vector<ll>> p : vec) {
        for (int i : p.second) cout << nums[i] << " ";
    }
}