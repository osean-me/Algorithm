#include <bits/stdc++.h>

using namespace std;

pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;

int main() {
    // make_tupl() 을 이용하여 pair 와 tuple 데이터 생성
    // tie() 를 이용하여 pair 와 tuple 에 담긴 값을 추출
    pi = {1, 2};
    tl = make_tuple(1, 2, 3);
    tie(a, b) = pi;
    cout << a << " : " << b << "\n";
    tie(a, b, c) = tl;
    cout << a << " : " << b << " : " << c << "\n";

    // pair 와 tuple 의 값을 직접 추출
    pi = {3, 4};
    a = pi.first;
    b = pi.second;
    cout << a << " : " << b << "\n";

    // get<>() 함수를 이용하여 tuple 에 담긴 데이터를 가져온다.
    // 보통은 3가지 이상의 변수가 필요하면 struct 을 사용해보자
    tl = make_tuple(4, 5, 6);
    a = get<0>(tl);
    b = get<1>(tl);
    c = get<2>(tl);
    cout << a << " : " << b << " : " << c << "\n";
    return 0;
}