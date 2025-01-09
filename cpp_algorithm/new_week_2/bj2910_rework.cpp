#include <bits/stdc++.h>

using namespace std;

int n, c, arr[1001];
vector<pair<int, int>> v;
map<int, int> countMap, indexMap;

bool cmp(pair<int, int> current, pair<int, int> prev) {
    if (current.first == prev.first) {
        return indexMap[current.second] < indexMap[prev.second];
    }

    return current.first > prev.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 카운트
        countMap[arr[i]]++;
        // 해당 숫자가 첫 번째로 나온 인덱스를 저장
        if (indexMap[arr[i]] == 0) indexMap[arr[i]] = (i + 1);
    }

    // 정렬을 위해 Vector 객체에 담는다.
    for (auto it : countMap) v.push_back({it.second, it.first});

    // 정렬
    sort(v.begin(), v.end(), cmp);

    // 출력
    for (pair<int, int> p : v) {
        for (int i = 0; i < p.first; i++) {
            cout << p.second << " ";
        }
    }
}