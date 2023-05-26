//
// Created by SeongHeon Sim on 2023/04/19.
//
#include <bits/stdc++.h>

using namespace std;

int findUnit(int multi, string target) {
    int n = stoi(target);
    int m = multi;
    for (int i = 0; i < target.length(); i++) {
        n = n % m;
        if (n < multi) break;
        m *= multi;
    }
    return n;
}

vector<int> getRule(int n) {
    vector<int> result = vector<int>();
    result.push_back(n);
    int nn = n;
    for (int i = 1; i < 9; i++) {
        nn *= n;
        int unit = findUnit(10, to_string(nn));
        if (unit == n) break;
        result.push_back(unit);
    }
    if (result.size() == 1 && result[0] == 0) result.push_back(10);
    return result;
}

/**
 * 잘못 접근한 풀이 방식
 * @return
 */
int main() {
    string x, y, z;
    cin >> x >> y >> z;
    int xx = findUnit(10, x);
    vector<int> xv = getRule(xx);
    int roofCnt = findUnit(xv.size(), y);
    int unit = xx;
    for (int i = 1; i < roofCnt; i++) unit *= xx;
    int zz = findUnit(10, z);
    if (unit < stoi(z)) cout << unit;
    else cout << unit % zz;
}
