#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj, answer;
stack<int> stck;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    adj.resize(n);
    answer.resize(n, -1);

    for (int i = 0; i < n; i++) cin >> adj[i];

    for (int i = 0; i < n; i++) {
        while (!stck.empty() && adj[stck.top()] < adj[i]) {
            answer[stck.top()] = adj[i];
            stck.pop();
        }
        stck.push(i);
    }

    for (int i = 0; i < n; i++) cout << answer[i] << " ";
}