#include <bits/stdc++.h>

using namespace std;

/**
 * fill(first, last, initVal) 함수는 O(n) 의 시간 복잡도를 가진다.
 */
int a[10];
int b[10][10];
int main() {
    // 배열로 정의된 a 변수의 0 ~ 9까지 100 으로 초기화한다.
    fill(&a[0], &a[10], 100);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }

    auto it = &a[0];
    // a[0] 요소에 대한 Iterator 를 통해 메모리 주소 출력
    cout << it << "\n";
    // a[1] 오소에 대한 Iterator 를 통해 메모리 주소 출력
    cout << it + 1 << "\n";
    // a[0] 요소의 값 출력
    cout << *it << "\n";
    // a[1] 요소의 값 출력
    cout << *(it + 1) << "\n";

    // 2차원 배열 초기화
    fill(&b[0][0], &b[9][9], 2);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    it = &b[0][0];
    cout << *it << "\n";  // 2차원 배열 b 의 1,1 위치에 있는 값 출력 > 2
    cout << *(it + 99) << "\n";  // 2차원 배열 b 의 9,9 위치에 있는 값 출력 > 0

    // 배열의 이름으로도 배열을 초기화 할 수 있다.
    // 1차원 배열의 경우 배열의 이름 + 숫자로 Iterator 를 호출 할 수 있다.
    int c[10];
    fill(c, c + 10, 10);
    for (int i = 0; i < 10; i++) {
        cout << c[i] << " ";
    }

    cout << "\n";

    // 2차원 배열에서는 Iterator 를 직접 호출하고 그 뒤에 숫자를 더해줘야 원하는
    // 요소에 접근 할 수 있다.
    int d[10][10];
    fill(&d[0][0], &d[0][0] + 10 * 9, 3);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}