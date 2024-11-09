#include <bits/stdc++.h>

using namespace std;

/**
 * Iterator 란 컨테이너에 저장되어 있는 요소의 주소를 가리키는 개체를 말한다.
 * 또는 포인터를 일반화한 것을 말한다.
 * vector, map 등 각각 다르게 구현된 컨테이너들을 일반화된 Iterator 를 사용하여
 * 쉽게 순회할 수 있다.
 *
 * 다만 주소값을 바로 반환하지는 못하며, &* 를 통해 한 단계 더 거쳐 가리키는
 * 해당 요소의 주소값을 반환할 수 있다.
 */
vector<int> v;

int main() {
    // v 에 0부터 5까지 값을 할당한다.
    for (int i = 0; i <= 5; i++) {
        v.push_back(i);
    }

    /**
     * 1부터 5까지 순회하면서
     * 1. 벡터의 각 인덱스에 할당된 값을 출력한다.
     * 2-1. v.begin() 함수를 호출하여 벡터의 첫 번째 요소에 접근하고, 해당 값에
     * + i 를 하여 현재 인덱스에 할당된 값에 접근한다.
     * 2-2. 각 인덱스에 할당된
     * 값의 메모리 주소를 출력한다.
     */
    for (int i = 0; i < 5; i++) {
        cout << i << "번째 요소 : " << *(v.begin() + i) << "\n";
        cout << &*(v.begin() + i) << '\n';
    }

    /**
     * 벡터의 end() 함수를 호출하여 벡터의 끝가지 순회할 수 있도록 한다.
     * 1. auto 는 변수 타입을 자동으로 설정하도록 하는 Operator 이다.
     * 2. auto 로 정의된 it 변수를 벡터의 첫 번째 요소로 초기화 하기위해
     * begin(0) 함수를 호출한다.
     * 3. 반복문을 순회하면서 it++ 를 하여 벡터의 다음 요소로 it 을 초기화하도록
     * 하고, 다음 요소로 초기화된 it 의 메모리 주소를 출력한다.
     */
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';

    /**
     * 바로 위의 반복문과 동일하지만 it 변수를 vector<int>::iterator 로
     * 초기화하도록 한다.
     */
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }

    // it 변수를 벡터의 첫 번째 요소로 초기화
    auto it = v.begin();
    // advance() 함수를 호출하여 벡터의 3 번째 요소를 가리키도록 한다.
    advance(it, 3);
    cout << '\n';
    // vector 의 세 번째 요소의 메모리 주소 출력
    cout << *it << '\n';
    return 0;
}