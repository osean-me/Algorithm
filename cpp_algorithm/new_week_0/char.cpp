#include <bits/stdc++.h>

using namespace std;

char getChar() {
    // char 타입은 값을 할당하지 않으면 null 문자로 초기화한다.
    // 이것은 빈 문자열이 아니다.
    char c;
    cin >> c;
    return c;
}

int main() {
    // char 타입은 작은 따옴표를 사용하고 1byte 의 크기를 갖는다.
    char a = 'a';
    cout << a << "\n";

    // char 배열이 아니기 때문에 여러 개의 문자를 입력하더라도 첫 번째 요소만
    // 할당되어 리턴한다.
    char b = getChar();
    cout << b << "\n";

    // null 문자로 초기화
    char c = '\0';
    cout << c << "\n";

    // null1 == null2 == null3
    // "" != null1 && "" != null2 && "" != null3
    char null1 = '\0';  // 문자 리터럴
    char null2 = 0;     // 정수 리터럴
    char null3 = NULL;
    string d = "";
    cout << "hello";
    if (null1 == null2) cout << 1;  // 1 == true
    if (null2 == null3) cout << 1;  // 1 == true
    // 빈 문자열은 아니다.
    if (string(1, a) == d) cout << 1;

    return 0;
}