#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj, answers;
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    adj.resize(n);
    answers.resize(n, -1);
    for (int i = 0; i < n; i++) cin >> adj[i];
    for (int i = 0; i < n; i++) {
        while (!s.empty() && adj[s.top()] < adj[i]) {
            answers[s.top()] = adj[i];
            s.pop();
        }
        s.push(i);
    }
    for (int answer : answers) cout << answer << " ";
}