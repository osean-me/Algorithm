#include <bits/stdc++.h>

using namespace std;

int n, t, p, r;
vector<pair<vector<int>, vector<int>>> nodes(51);

void remove_parents() {
    for (int parent : nodes[t].first) {
        for (int i = 0; i < nodes[parent].second.size(); i++) {
            if (nodes[parent].second[i] == t) {
                nodes[parent].second.erase(nodes[parent].second.begin() + i);
                break;
            }
        }
    }
}

void remove_children(int node) {
    for (int child : nodes[node].second) remove_children(child);
    nodes[node].first.clear();
    nodes[node].second.clear();
}

int counting(int node) {
    if (nodes[node].second.empty()) return 1;
    int cnt = 0;
    for (int child : nodes[node].second) {
        if (!nodes[child].second.empty()) {
            cnt += counting(child);
        } else {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p == -1) {
            r = i;
            continue;
        }
        nodes[i].first.push_back(p);   // 현재 노드의 부모 노드 추가
        nodes[p].second.push_back(i);  // 부모 노드의 자식 노드 추가
    }

    cin >> t;

    if (t == r) {
        cout << 0;
        return 0;
    }

    remove_parents();
    remove_children(t);

    cout << counting(r);
}