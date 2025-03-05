#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj, answer;
stack<int> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    adj.resize(n);
    answer.resize(n, -1);

    for (int i = 0; i < n; i++) cin >> adj[i];

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && adj[stk.top()] < adj[i]) {
            answer[stk.top()] = adj[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i 0; i < n; i++) cout << answer[i] << " ";
}