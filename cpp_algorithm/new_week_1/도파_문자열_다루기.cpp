#include <bits/stdc++.h>

using namespace std;

int main() {
    string dopa = "umzunsik";

    // Q1. 앞에서부터 3개의 문자열을 출력하라.
    string a = dopa.substr(0, 3);
    cout << a << "\n";

    // Q2. 해당 문자열을 거꾸로해서 출력하라.
    reverse(a.begin(), a.end());
    cout << a << "\n";

    // Q3. 거꾸로 된 해당 문자열 긑에 "umzunsik" 이란 문자열을 추가하라.
    cout << a + dopa << "\n";
    return 0;
}