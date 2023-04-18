//
// Created by SeongHeon Sim on 2023/04/19.
//
#include <bits/stdc++.h>

using namespace std;

/**
 * 파라미터의 1의 자리값 찾기
 * @param target 입력값
 * @return 입력값의 1의 자리
 */
int findUnit(string target) {
    int n = stoi(target);
    int multi = 10;
    for (int i = 0; i < target.length(); i++) {
        n = n % multi;
        if (n < 10) break;
        multi *= 10;
    }
    return n;
}

/**
 * 1의 자리의 제곱 규칙 찾기
 * @param n 입력값의 1의 자리
 * @return n 부터 n 이 다시 나오기 전까지의 제곱값에 대한 1의 자리 배열
 */
vector<int> getRule(int n) {
    vector<int> result = vector<int>();
//    result.push_back(n);
    int nn = n;
    for (int i = 1; i < 9; i++) {
        nn *= n;
        int unit = findUnit(to_string(nn));
        result.push_back(unit);
        if (unit == n) break;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << i << "] : " << result[i] << "\n";
    }
    return result;
}

// 로직 잘못 됐다.
int findSquareUnit(int n, vector<int> v) {
    int result;
    if (n < v.size()) result = v[n - 1];
    else result = v[n - v.size() - 1];
    return result;
}

int main() {
    string x, y, z;
    cin >> x >> y >> z;
    // 1. x 의 1의 자리를 찾아야 한다. 이를 nn 이라고 하겠다.
    // 2. z 를 n 번 곱했을 때 1 의 자리가 z 인 경우를 찾아야 한다.
    // 3. nn 의 y 제곱
    int yy = findUnit(y);

    int xx = findUnit(x);
    cout << "x 의 1의 자리 : " << xx << "\n";
    vector<int> xv = getRule(xx);
    int xSquareUnit = findSquareUnit(yy, xv);
    cout << x << "^" << y << "의 1의 자리수 : " << xSquareUnit << "\n";

    int zz = findUnit(z);
    cout << "z 의 1의 자리 : " << zz << "\n";
    vector<int> zv = getRule(zz);
    int zSquareUnit = findSquareUnit(yy, zv);
    cout << z << "^" << y << "의 1의 자리수 : " << zSquareUnit << "\n";

    cout << (xSquareUnit % zSquareUnit);
}
