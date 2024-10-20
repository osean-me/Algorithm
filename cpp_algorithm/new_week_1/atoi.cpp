#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "1";
    string s2 = "amumu";
    // 숫자형으로 변환 가능하면 변환한 숫자형 데이터를 리턴
    cout << atoi(s.c_str()) << "\n";
    // 숫자형으로 변환 불가능하면 0 리턴
    cout << atoi(s2.c_str()) << "\n";

    return 0;
}