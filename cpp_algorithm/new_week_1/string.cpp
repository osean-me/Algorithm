#include <bits/stdc++.h>

using namespace std;

string a;

int main() {
    // 한글은 한 글자당 3bytes 영어는 한 글자당 1bytes
    string a = "나는야";
    cout << a[0] << "\n";                  // output : ?
    cout << a[0] << a[1] << a[2] << '\n';  // output :
    cout << a << "\n";                     // output : 나는야

    string b = "abc";
    cout << b[0] << "\n";                  // output : a
    cout << b[0] << b[1] << b[2] << "\n";  // output : a / a b c / b
    cout << b << "\n";

    // string 타입에서 자주 사용하는 함수들
    string str = "love is";
    // result : love is pain!
    str += " pain!";
    // result : love is pain
    str.pop_back();
    // output : love is pain : 12
    cout << str << " : " << str.size() << "\n";
    // output : l
    cout << char(*str.begin()) << '\n';
    // output : n
    cout << char(*(str.end() - 1)) << '\n';
    // result : testlove is pain
    str.insert(0, "test");
    // output : testlove is pain : 16
    cout << str << " : " << str.size() << "\n";
    // result : ove is pain
    str.erase(0, 5);
    // output : ove is pain : 11
    cout << str << " : " << str.size() << "\n";
    // result : 18446744073709551615
    // -> bit 가 모두 1로 이뤄진 가장 큰 수
    // -> 존재하지 않는다는 의미
    auto it = a.find("love");
    // love 라는 문자열은 포함되어 있지 않으니 조건문을 통과하지 않는다.
    if (it != string::npos) cout << "포함되어 있다." << '\n';
    // output : 18446744073709551615
    cout << it << '\n';
    // output : 18446744073709551615
    cout << string::npos << '\n';
    // output : "s " (공란 표현을 위해 큰 따옴표 사용)
    cout << str.substr(5, 2) << '\n';
    // result : ove is pain!
    // push_back() 는 하나의 문자만 넣을 수 있다.
    str.push_back('!');
    cout << str << " : " << str.size() << "\n";
    return 0;
}