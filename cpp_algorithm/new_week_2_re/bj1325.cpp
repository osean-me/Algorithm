#include <bits/stdc++.h>

using namespace std;

int n, m, cnode, pnode;
int visited[10001];
vector<int> nodes[10001];
pair<int, vector<int>> answer = {0, vector<int>()};

int go(int p) {
    visited[p] = 1;
    if (nodes[p].empty()) return 1;

    int cnt = 1;
    for (int c : nodes[p]) {
        if (visited[c]) continue;
        cnt += go(c);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> cnode >> pnode;
        nodes[pnode].push_back(cnode);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = go(i);

        if (answer.first < cnt) {
            answer = {cnt, vector<int>(1, i)};
            continue;
        }

        if (answer.first == cnt) {
            answer.second.push_back(i);
            continue;
        }
    }
    sort(answer.second.begin(), answer.second.end());
    for (int computer : answer.second) cout << computer << " ";
}